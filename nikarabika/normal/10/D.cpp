//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 510;
int dp[maxn][maxn];
pii par[maxn][maxn];
int a[maxn],
	b[maxn],
	n, m;

int Find(int val, int pos){
	while(pos and b[pos] != val) pos--;
	return pos;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	a[0] = b[0] = -1;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			int pos = Find(a[i], j);
			if(pos){
				dp[i][j] = 1;
				for(int k = 0; k < i; k++)
					if(a[k] < a[i] and dp[k][pos - 1] + 1 >= dp[i][j]){
						dp[i][j] = dp[k][pos - 1] + 1;
						par[i][j] = {k, pos - 1};
					}
			}
		}
	
//	for(int i = 1; i <= n; i++, cout << endl)
//		for(int j = 1; j <= m; j++)
//			cout << dp[i][j] << ' ';

	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(dp[i][m] > dp[ans][m])
			ans = i;
	pii cur(ans, m);
	vector<int> vec;
	while(dp[cur.L][cur.R]){
		vec.PB(a[cur.L]);
		cur = par[cur.L][cur.R];
	}
	reverse(all(vec));
	cout << sz(vec) << '\n';
	for(int i = 0; i < sz(vec); i++)
		cout << vec[i] << " \n"[i == sz(vec) - 1];
	return 0;
}