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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 1e5 + 85 - 69;
int n, v;
vector<pii> veh[2];
int sum[2][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> v;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		veh[fi - 1].PB(MP(se, i + 1));
	}
	for(int i = 0; i < 2; i++){
		sort(veh[i].begin(), veh[i].end(), greater<pii>());
		for(int j = 0; j < sz(veh[i]); j++)
			sum[i][j + 1] = sum[i][j] + veh[i][j].L;
	}
	int ans = -1, cnt1, cnt2;
	for(int i = 0; i <= min(sz(veh[0]), v); i++){
		int rem = min((v - i) / 2, sz(veh[1]));
		if(sum[0][i] + sum[1][rem] > ans)
			ans = sum[0][i] + sum[1][rem], cnt1 = i, cnt2 = rem;
	}
	cout << ans << endl;
	for(int i = 0; i < cnt1; i++)
		cout << veh[0][i].R << ' ';
	for(int i = 0; i < cnt2; i++)
		cout << veh[1][i].R << ' ';
	cout << endl;
	return 0;
}