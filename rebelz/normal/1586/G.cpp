#include<bits/stdc++.h>

#define y1 dmytxdy
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

const int cys=1000000007;
int n,m,ncnt;
int vs[200005],lch[6000005],rch[6000005];
ll sum[6000005];
pii a[200005],p[200005];
bool vis[200005],hv[400005];

ll mod(ll x){return x>=cys?x-cys:x;}

int change(int id,int l,int r,int x,ll c){
	int rt=++ncnt;
	lch[rt]=lch[id],rch[rt]=rch[id],sum[rt]=mod(sum[id]+c);
	if(l==r) return rt;
	int mid=(l+r)/2;
	if(x<=mid) lch[rt]=change(lch[id],l,mid,x,c);
	else rch[rt]=change(rch[id],mid+1,r,x,c);
	return rt;
}

ll query(int id,int l,int r,int ql,int qr){
	if(!id) return 0;
	if(l==ql&&r==qr) return sum[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(lch[id],l,mid,ql,qr);
	else if(ql>mid) return query(rch[id],mid+1,r,ql,qr);
	else return mod(query(lch[id],l,mid,ql,mid)+query(rch[id],mid+1,r,mid+1,qr));
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=readint();
	for(int i=1;i<=n;i++) p[i]=mp(a[i].fi,i);
	sort(p+1,p+n+1);
	for(int i=n;i>=1;i--){
		int tmp=a[p[i].se].se;
		ll val=query(vs[i+1],1,n+n,1,tmp);
		vs[i]=change(vs[i+1],1,n+n,tmp,mod(val+1));
	}
	m=readint();
	for(int i=1;i<=m;i++) vis[readint()]=1;
	priority_queue<int> q;
	for(int i=1;i<=n;i++) if(vis[i]) q.push(a[i].se);
	ll ans=0;
	int maxa=q.top();
	for(int i=1;i<=n;i++){
		if(maxa<a[p[i].se].se) continue;
		ans=mod(ans+query(vs[i+1],1,n+n,1,a[p[i].se].se)+1);
		hv[a[p[i].se].se]=1;
		if(maxa==a[p[i].se].se){
			q.pop();
			while(1){
				if(q.empty()){
					printf("%lld\n",ans);
					return 0;
				}
				maxa=q.top();
				if(hv[maxa]) q.pop();
				else break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}