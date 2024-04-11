#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define ull unsigned long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
ull a[N],b[N],sum[N],seed;
map<ull,ll> f;
map<ull,int> g;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1){
		int l,r;
		scanf("%d%d",&l,&r);
		seed=((ull)rand()<<48)+((ull)rand()<<32)+((ull)rand()<<16)+rand();
	//	cout<<seed<<"seed\n";
		a[l]^=seed;a[r+1]^=seed;
		b[l]^=seed;
	}
	ll ans=0;
	rep(i,1,m+1){
		a[i]^=a[i-1];
		b[i]^=b[i-1];
		sum[i]=sum[i-1]^a[i];
		f[sum[i]^b[i]]+=i-1;
		g[sum[i]^b[i]]++;
		ans+=(ll)i*g[sum[i]^b[i]]-f[sum[i]^b[i]];
	}
	int pos=0;
	rep(i,1,m+1){
		if(!a[i]){
			ans-=1ll*(i-pos)*(i-pos+1)/2;
		}
		else{
			pos=i;
		}
	}
	printf("%lld",ans);
}