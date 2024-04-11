#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int val[600000];
	void change(int id,int l,int r,int x,int c){
		val[id]+=c;
		if(l==r) return;
		int mid=(l+r)/2;
		if(x<=mid) change(id<<1,l,mid,x,c);
		else change(id<<1|1,mid+1,r,x,c);
	}
	int findl(int id,int l,int r){
		if(l==r) return l;
		int mid=(l+r)/2;
		if(val[id<<1]) return findl(id<<1,l,mid);
		else return findl(id<<1|1,mid+1,r);
	}
	int findr(int id,int l,int r){
		if(l==r) return r;
		int mid=(l+r)/2;
		if(val[id<<1|1]) return findr(id<<1|1,mid+1,r);
		else return findr(id<<1,l,mid);
	}
	int query(int id,int l,int r,int ql,int qr){
		if(l==ql&&r==qr) return val[id];
		int mid=(l+r)/2;
		if(qr<=mid) return query(id<<1,l,mid,ql,qr);
		else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
		else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
	}
	int getl(int id,int l,int r){
		if(l==r) return l;
		int mid=(l+r)/2;
		if(val[id<<1]!=mid-l+1) return getl(id<<1,l,mid);
		else return getl(id<<1|1,mid+1,r);
	}
	int getr(int id,int l,int r){
		if(l==r) return r;
		int mid=(l+r)/2;
		if(val[id<<1|1]!=r-mid) return getr(id<<1|1,mid+1,r);
		else return getr(id<<1,l,mid);
	}
}t[4];

int n,q;
int a[200005];
char s[200005];

int getans(){
	int ans=0;
	for(int i=1;i<=3;i++){
		int l=t[i%3+1].findl(1,1,n),r=t[i%3+1].findr(1,1,n);
//		cout<<"test "<<i<<' '<<l<<' '<<r<<' '<<a[l]<<endl;
		if(a[l]==i%3+1){
			ans+=t[i].query(1,1,n,l,r);
			int pl=t[i].getl(1,1,n),pr=t[i].getr(1,1,n);
			ans+=pl-1+n-pr;
		}
		else if(t[i].val[1]==n) ans+=n;
	}
	return ans;
}

int main(){
	n=readint(); q=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]=='R'?1:s[i]=='S'?2:3;
	for(int i=1;i<=n;i++) t[a[i]].change(1,1,n,i,1);
	printf("%d\n",getans());
	int x,y; char z[3];
	while(q--){
		x=readint(); scanf("%s",z);
		y=z[0]=='R'?1:z[0]=='S'?2:3;
		t[a[x]].change(1,1,n,x,-1);
		t[y].change(1,1,n,x,1);
		a[x]=y;
		printf("%d\n",getans());
	}
	return 0;
}