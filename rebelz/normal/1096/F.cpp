#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int cys=998244353;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,cnt;
ll a[200005],b[200005],c[200005],vis[200005];

struct node{
	ll a,b;
	node(ll aa=0,ll bb=0):a(aa),b(bb){}
	node operator+(const node c)const{
		node ret;
		ret.b=b*c.b%cys,ret.a=(b*c.a%cys+a*c.b%cys)%cys;
		return ret;
	}
	node operator/(const ll c)const{
		return node(a,b*c%cys);
	}
};

struct seg{
	int left,right;
	node lazy,sum;
};

struct segtree{
	seg t[600000];
	
	void update(int id){
		t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
		if(t[id<<1].lazy.a>0) t[id].sum=t[id].sum+node(t[id<<1].lazy.a*(t[id<<1].right-t[id<<1].left+1)%cys,t[id<<1].lazy.b);
		if(t[id<<1|1].lazy.a>0) t[id].sum=t[id].sum+node(t[id<<1|1].lazy.a*(t[id<<1|1].right-t[id<<1|1].left+1)%cys,t[id<<1|1].lazy.b);
	}
	
	void pushdown(int id){
		if(t[id].lazy.a>0){
			t[id<<1].lazy=t[id<<1].lazy+t[id].lazy;
			t[id<<1|1].lazy=t[id<<1|1].lazy+t[id].lazy;
			t[id].sum=t[id].sum+node(t[id].lazy.a*(t[id].right-t[id].left+1)%cys,t[id].lazy.b);
			t[id].lazy.a=0,t[id].lazy.b=1;
		}
	}
	
	void build(int id,int l,int r){
		t[id].left=l,t[id].right=r,t[id].lazy.b=t[id].sum.b=1;
		if(l==r) return;
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
	}
	
	void change(int id,int l,int r,node c){
		if(t[id].left==l&&t[id].right==r){
			t[id].lazy=t[id].lazy+c;
			return;
		}
		pushdown(id);
		if(t[id<<1].right>=r) change(id<<1,l,r,c);
		else if(t[id<<1|1].left<=l) change(id<<1|1,l,r,c);
		else change(id<<1,l,t[id<<1].right,c),change(id<<1|1,t[id<<1|1].left,r,c);
		update(id);
	}
	
	node query(int id,int l,int r){
		if(t[id].left==l&&t[id].right==r) return t[id].sum+node(t[id].lazy.a*(t[id].right-t[id].left+1)%cys,t[id].lazy.b);
		pushdown(id);
		if(t[id<<1].right>=r) return query(id<<1,l,r);
		else if(t[id<<1|1].left<=l) return query(id<<1|1,l,r);
		else return query(id<<1,l,t[id<<1].right)+query(id<<1|1,t[id<<1|1].left,r);
	}
}t1,t2,t3;

ll power(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		a[i]=readint();
		if(a[i]>-1) vis[a[i]]=1;
	}
	for(int i=1;i<=n;i++) if(!vis[i]) b[++cnt]=i,c[i]=cnt;
	t1.build(1,1,cnt+1); t2.build(1,1,n); t3.build(1,1,cnt+1);
	node ans; ans.a=0,ans.b=1;
	int num=0;
	for(int i=n;i>=1;i--){
//		cout<<ans.a<<' '<<ans.b<<endl;
//		cout<<"FDSLFD "<<t3.query(1,1,cnt).a<<' '<<t3.query(1,1,cnt).b<<endl;
		if(a[i]==-1) ans=ans+node(num,2)+t3.query(1,1,cnt)/cnt,num++;
		else ans=ans+t1.query(1,1,lower_bound(b+1,b+cnt+1,a[i])-b)+t2.query(1,1,a[i]);
//		cout<<"TEST "<<ans.a<<' '<<ans.b<<endl;
		if(a[i]==-1) t1.change(1,2,cnt+1,node(1,cnt));
		else t2.change(1,a[i],a[i],node(1,1)),t3.change(1,lower_bound(b+1,b+cnt+1,a[i])-b,cnt+1,node(1,1));
	}
	cout<<power(ans.b,cys-2)*ans.a%cys<<endl;
	return 0;
}