
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;
#define F first
#define S second
#define pb push_back
//---------END-------//
const ll INF=1e9+10,M=2e5+100,MO=1e9+7,ML=25;
ll seg[4*M],lz[4*M],p[M],b=727;
vector<ll> v[M];
ll merge(ll x,ll y,ll z){
	return (x*p[z]+y)%MO;
}
void shift(int id,int b,int e){
	if(lz[id]==0) return;
	int m=(b+e)/2;
	seg[id*2]=v[1][m-b-1]*lz[id]%MO;
	seg[id*2+1]=v[1][e-m-1]*lz[id]%MO;
	lz[id*2]=lz[id];
	lz[id*2+1]=lz[id];
	lz[id]=0;
}
ll g(int id,int b,int e,int l,int r){
	if(r<=b||e<=l) return 0;
	if(l<=b&&e<=r) return seg[id];
	int m=(b+e)/2;
	shift(id,b,e);
	return merge(g(id*2,b,m,l,r),g(id*2+1,m,e,l,r),max(0,min(r,e)-max(l,m)));
}
void upd(int id,int b,int e,int l,int r,ll x){
	if(r<=b||e<=l) return;
	if(l<=b&&e<=r){
		lz[id]=x;
		seg[id]=v[1][e-b-1]*x%MO;
		return;
	}
	shift(id,b,e);
	int m=(b+e)/2;
	upd(id*2,b,m,l,r,x);
	upd(id*2+1,m,e,l,r,x);
	seg[id]=merge(seg[id*2],seg[id*2+1],e-m);
}
int main(){
    fio;
	int n,q,m;
	cin>>n>>q>>m;
	q+=m;
	string s;
	cin>>s;
	p[0]=1;
	for(int i=1;i<=n;i++)
		p[i]=p[i-1]*b%MO;
	for(int i=1;i<=n;i++){
		v[i].pb(1);
		for(int j=i;j<=n;j+=i){
			ll x=v[i].back();
			v[i].pb((x+p[j])%MO);
		}
	}
	for(int i=0;i<n;i++)
		upd(1,0,n,i,i+1,s[i]-'0'+1);
	while(q--){
		ll t,l,r,x;
		cin>>t>>l>>r>>x;
		l--;
		if(t==1)
			upd(1,0,n,l,r,x+1);
		else{
			ll y=g(1,0,n,l,l+x);
			y=y*(v[x][(r-l)/x-1])%MO;
			y=merge(y,g(1,0,n,l,l+(r-l)%x),(r-l)%x);
			if(y==g(1,0,n,l,r))
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
}