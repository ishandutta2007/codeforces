#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ cin >> x; }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int main(){
	int n;
	read(n);
	int data[110];
	int dp[110][3];
	int inf=1e9;
	dp[0][0] = 0;
	dp[0][1] = inf;
	dp[0][2] = inf;
	for(int i=1; i<=n; ++i){
		read(data[i]);
		for(int j=0; j<3; ++j) dp[i][j]=inf;
		if(data[i] >= 2){
			dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][2]));
		}
		if(data[i]&1){
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
		}
		dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]})+1;
	}
	printf("%d\n", min({dp[n][0], dp[n][1], dp[n][2]}));
	return 0;
}