using namespace std;

#include <iostream>

#define MAXN 45
#define fi first
#define se second

int N,M,a[MAXN][MAXN];

void solve() {
	cin >> N >> M;
	pair<long long,pair<int,int>> uwu = {-1e18,{-1,-1}};
	for(int i = 1;i <= N;++i) {
		for(int j = 1;j <= M;++j) {
			cin >> a[i][j];
			uwu = max(uwu,{a[i][j],{i,j}});
		}
	}
	long long ans = max(uwu.se.fi,N - uwu.se.fi + 1) * max(uwu.se.se,M - uwu.se.se + 1);
	cout << ans << endl;
	return;
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}