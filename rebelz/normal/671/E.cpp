// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,top;
ll tag[600000],maxa[600000],rson[600000],maxb[600000],a[200005],s[200005];

void addtag(int id,ll c){
	tag[id]+=c,maxa[id]+=c;
}

void pushdown(int id){
	if(tag[id]){
		addtag(id<<1,tag[id]);
		addtag(id<<1|1,tag[id]);
		tag[id]=0;
	}
}

ll getans(int id,int l,int r,ll c){
	if(l==r) return maxb[id]-max(c,maxa[id]);
	pushdown(id);
	int mid=(l+r)/2;
	if(c<maxa[id<<1]) return max(getans(id<<1,l,mid,c),rson[id]);
	else return max(maxb[id]-c,getans(id<<1|1,mid+1,r,c));
}

void update(int id,int l,int r){
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
	int mid=(l+r)/2;
	rson[id]=getans(id<<1|1,mid+1,r,maxa[id]);
}

void change(int id,int l,int r,int ql,int qr,ll c){
	if(l==ql&&r==qr) return addtag(id,c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id,l,r);
}

ll getmax(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return maxa[id];
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return getmax(id<<1,l,mid,ql,qr);
	else if(ql>mid) return getmax(id<<1|1,mid+1,r,ql,qr);
	else return max(getmax(id<<1,l,mid,ql,mid),getmax(id<<1|1,mid+1,r,mid+1,qr));
}

int query(int id,int l,int r,int ql,int qr,ll c){
	if(getans(id,l,r,c)<-k) return l-1;
	if(l==r) return l;
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,c);
	else{
		int tmp=query(id<<1|1,mid+1,r,mid+1,qr,max(c,getmax(id<<1,l,mid,ql,mid)));
		if(tmp>mid) return tmp;
		else return query(id<<1,l,mid,ql,mid,c);
	}
}

void build(int id,int l,int r){
	if(l==r) return (void)(maxa[id]=maxb[id]=a[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id,l,r);
	maxb[id]=max(maxb[id<<1],maxb[id<<1|1]);
}

void cover(int id,int l,int r,int x,ll c){
	if(l==r) return (void)(maxa[id]=maxb[id]=c);
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) cover(id<<1,l,mid,x,c);
	else cover(id<<1|1,mid+1,r,x,c);
	update(id,l,r);
	maxb[id]=max(maxb[id<<1],maxb[id<<1|1]);
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<n;i++) a[i+i+1]=-readint();
	for(int i=1;i<=n;i++) a[i+i]=readint();
	for(int i=1;i<=n+n;i++) a[i]+=a[i-1];
	build(1,1,n+n);
	s[0]=n+n+1;
	int ans=0;
	for(int i=n+n;i>=1;i--){
		if(i&1){
			while(top&&a[i]<=a[s[top]]){
				if(top-1) change(1,1,n+n,s[top-1],n+n,a[s[top-1]]-a[s[top]]);
				top--;
			}
			if(top) change(1,1,n+n,s[top],n+n,a[i]-a[s[top]]);
			s[++top]=i;
			int L=1,R=top,res=0;
			while(L<=R){
				int mid=(L+R)/2;
				if(a[i]-a[s[mid]]<=k) res=mid,R=mid-1;
				else L=mid+1;
			}
			chkmax(ans,(query(1,1,n+n,i,s[res-1]-1,-(1ll<<60))-i+1)/2);
			cover(1,1,n+n,i,a[i-1]);
		}
	}
	printf("%d\n",ans);
	return 0;
}