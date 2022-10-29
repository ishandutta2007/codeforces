#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
const int N=2003;
const int mod=1e9+7;
int tag[N<<2],mn[N<<2],mx[N<<2],sum[N<<2];
vi vx,vy;
void solve(int pos,int l,int r,int v){
	tag[pos]=mx[pos]=mn[pos]=v;
	sum[pos]=1ll*(vx.back()-vx[v])*(vx[r]-vx[l])%mod;
//	cout<<vx.back()<<' '<<vx[v]<<' '<<vx[r]<<' '<<vx[l]<<"WA\n";
}
void pushup(int pos){
	sum[pos]=(sum[pos<<1]+sum[pos<<1|1])%mod;
	mn[pos]=min(mn[pos<<1],mn[pos<<1|1]);
	mx[pos]=max(mx[pos<<1],mx[pos<<1|1]);
}
void pushdown(int pos,int l,int r){
	if(tag[pos]==-1)return;
	int m=l+r>>1; 
	solve(pos<<1,l,m,tag[pos]);
	solve(pos<<1|1,m,r,tag[pos]);
	tag[pos]=-1;
}
void build(int pos,int l,int r,const vi& a){
	tag[pos]=-1;
	if(l+1==r){
		mn[pos]=mx[pos]=a[l];
		sum[pos]=1ll*(vx.back()-vx[a[l]])*(vx[r]-vx[l])%mod;
	//	cout<<l<<' '<<r<<' '<<vx.back()<<' '<<vx[a[l]]<<' '<<vx[r]<<' '<<vx[l]<<"sum\n";
		return;
	}
	int m=l+r>>1;
	build(pos<<1,l,m,a);
	build(pos<<1|1,m,r,a);
	pushup(pos);
}
void upd(int pos,int l,int r,int x,int y,int v){
	if(l>=y||r<=x||mn[pos]>=v)return;
	if(l>=x&&r<=y&&mx[pos]<=v){
	//	cout<<"comein\n";
		solve(pos,l,r,v);
		return;
	}
	pushdown(pos,l,r);
	int m=l+r>>1;
	upd(pos<<1,l,m,x,y,v);
	upd(pos<<1|1,m,r,x,y,v);
	pushup(pos);
}
int main() {
    int n,k,L;
    scanf("%d%d%d",&n,&k,&L);
    vi x(n),y(n),c(n);
    rep(i,0,n){
        scanf("%d%d%d",&x[i],&y[i],&c[i]);
        --c[i];
    }
    vx=x,vy=y;
    vx.pb(-1);
    vx.pb(L);
    vy.pb(-1);
    vy.pb(L);
    sort(all(vx));
    sort(all(vy));
    vi px(n),py(n);
    iota(all(px),0);
    iota(all(py),0);
    sort(all(px),[&](int i,int j){
        return x[i]<x[j];
    });
    sort(all(py),[&](int i,int j){
        return y[i]<y[j];
    });
    rep(i,0,n)x[px[i]]=y[py[i]]=i+1;
    ll ans=0;
    for(int u=k;u<=n;++u){
        vi r(n,n+1),cnt(k);
        vector<set<int>> s(n);
        int cur=0;
        for(int l=0,i=0;l<n;++l){
        	while(i<n&&cur<k){
        		int j=px[i];
				if(y[j]<=u&&!cnt[c[j]]++)cur++;
				++i; 
			}
			if(cur==k)r[l]=i;
			int j=px[l];
			if(y[j]<=u&&!--cnt[c[j]])--cur;
		} 
		build(1,0,n,r);
		rep(i,0,n){
			if(y[i]<=u)s[c[i]].insert(x[i]);
		}
		ll res=0;
		for(int d=0;d<u;++d){
			res=(res+1ll*(vy[d+1]-vy[d])*sum[1])%mod;
		//	cout<<u<<' '<<d<<' '<<vy[d+1]<<' '<<vy[d]<<' '<<sum[1]<<"??\n"; 
			int j=py[d];
			auto it=s[c[j]].erase(s[c[j]].find(x[j]));
			int r=it==s[c[j]].end()?n+1:*it;
			int l=it==s[c[j]].begin()?0:*prev(it);
		//	cout<<l<<' '<<r<<"range\n";
			upd(1,0,n,l,x[j],r);
		}
	//	cout<<res<<"res\n";
		ans=(ans+1ll*res*(vy[u+1]-vy[u]))%mod;
	//	cout<<ans<<"ans\n";
    }
    printf("%lld\n",ans);
	return 0;
}