#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 20;

ll dp[1 << N];

struct man{
	int cost;
	int monitors;
	int mask;
	bool operator<(man &b){
		return monitors < b.monitors;
	}
};

int main(){
	fastIO;
	int n, m;
	ll b;
	cin >> n >> m >> b;
	man p[n];
	int s;
	int z;
	for(int i = 0; i < n;i ++ ){
		cin >> p[i].cost >> p[i].monitors >> s;
		p[i].mask = 0;
		for(int j = 0; j < s; j ++ ){
			cin >> z;
			-- z;
			p[i].mask |= (1 << z); 
		}
	}
	sort(p, p + n);
	int total = 0;
	for(int i = 0; i < m; i ++ )
		total |= (1 << i);
	for(int i = 0; i < (1 << m); i ++ )
		dp[i] = (ll)4e18;
	dp[0] = 0;
	ll ans = (ll)4e18;
	for(int i = 0; i < n; i ++ ){
		for(int j = 0; j < (1 << m); j ++ ){
			dp[j | p[i].mask] = min(dp[j | p[i].mask], dp[j] + p[i].cost);
		}
		ans = min(ans, dp[total] + 1ll * b * p[i].monitors);
	}
	if(ans == (ll)4e18){
		cout << -1;
	}
	else{
		cout << ans << "\n";
	}
	return 0;
}