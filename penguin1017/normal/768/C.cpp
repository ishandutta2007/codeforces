#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll p=1e9+7;
int a[N],cnt,maxn[N],mini[N];
map<ll,int> id;
int main(){
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	rep(i,0,n)scanf("%d",&a[i]);
	sort(a,a+n);
	ll seed=0;
	int last,T;
	rep(i,0,n)seed=(seed*p+a[i])%mod;
	if(!id.count(seed))id[seed]=cnt++;
	maxn[0]=a[n-1],mini[0]=a[0];
	while(k--){
		rep(i,0,n){
			if(i&1)continue;
			else a[i]^=x;
		}
		sort(a,a+n);
		maxn[cnt]=a[n-1],mini[cnt]=a[0];
		seed=0;
		rep(i,0,n)seed=(seed*p+a[i])%mod;
		if(!id.count(seed))id[seed]=cnt++;
		else{
			T=cnt-id[seed];
			last=k%T;
			printf("%d %d",maxn[id[seed]+last],mini[id[seed]+last]);
			return 0;
		}
	}
	cout<<a[n-1]<<' '<<a[0];
}
/*
10 200 69
54 36 102 160 35 48 27 44 33 65
*/