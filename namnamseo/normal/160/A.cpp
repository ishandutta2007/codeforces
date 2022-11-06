#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <stack>
using namespace std;
#define sz(v) ((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int n;
int d[101];
int dp[101][10001];

int main(){
	read(n);
	int i,j;
	int sum=0;
	for(i=1;i<=n;++i) read(d[i]), sum+=d[i];
	for(i=1;i<=10000;++i) dp[0][i]=2e9;
	for(i=1;i<=n;++i){
		for(j=0;j<=sum;++j){
			dp[i][j]=dp[i-1][j];
			if(j>=d[i]) dp[i][j]=min(dp[i][j],1+dp[i-1][j-d[i]]);
		}
	}
	int ans=2e9;
	for(i=sum/2+1;i<=sum;++i) ans=min(ans, dp[n][i]);
	printf("%d\n",ans);
	return 0;
}