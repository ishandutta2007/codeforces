#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
const int Maxn=300000;
priority_queue<int,vector<int>,greater<int> > q;
int n,m;
int k[Maxn+5];
int c[Maxn+5];
ll sum_c[Maxn+5],sum_k[Maxn+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	sort(k+1,k+1+n);
	for(int i=1;i<=m;i++){
		sum_c[i]=sum_c[i-1]+c[i];
	}
	for(int i=1;i<=n;i++){
		sum_k[i]=sum_k[i-1]+c[k[i]];
	}
	ll ans=Inf;
	for(int i=n;i>=0;i--){
		if(n-i>m){
			break;
		}
		ans=min(ans,sum_c[n-i]+sum_k[i]);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}