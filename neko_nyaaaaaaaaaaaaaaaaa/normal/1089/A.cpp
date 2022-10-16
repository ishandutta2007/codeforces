#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
void solve()
{
	int aa, bb; cin >> aa >> bb;
	int diff = abs(aa-bb);

	vector<string> score;
	score.push_back("AAA");
	score.push_back("BAAA");
	score.push_back("BBAAA");
	score.push_back("AABBB");
	score.push_back("ABBB");
	score.push_back("BBB");

	for (auto s: score) {
		int m = s.size();
		for (int i = 0; i < (1 << m); i++) {
			vector<pair<int, int>> score(m);
			// 25, 25, 25, 25, 15
			int a = aa, b = bb;
			for (int j = 0; j < m; j++) {
				if (s[j] == 'A') {
					int sc = (j == 4 ? 15 : 25);
					a -= sc; score[j].first += sc;
				} else {
					int sc = (j == 4 ? 15 : 25);
					b -= sc; score[j].second += sc;
				}

				if (i & (1 << j)) {
					if (s[j] == 'A') {
						int sc = (j == 4 ? 13 : 23);
						b -= sc; score[j].second += sc;
					} else {
						int sc = (j == 4 ? 13 : 23);
						a -= sc; score[j].first += sc;
					}
				}
			}

			if (a < 0 || b < 0) continue;
			for (int j = 0; j < m; j++) {
				if (i & (1 << j)) {
					int k = min(a, b);
					score[j].first += k;
					score[j].second += k;
					a -= k; b -= k;
					break;
				}
			}

			for (int j = 0; j < m; j++) {
				if (i & (1 << j)) continue;

				if (s[j] == 'A') {
					int sc = min(b, (j == 4 ? 13 : 23));
					b -= sc; score[j].second += sc;
				} else {
					int sc = min(a, (j == 4 ? 13 : 23));
					a -= sc; score[j].first += sc;
				}
			}

			if (a == 0 && b == 0) {
				int as = 0, bs = 0;
				for (char c: s) {
					as += (c == 'A');
					bs += (c == 'B');
				}
				cout << as << ":" << bs << '\n';
				for (auto [x, y]: score) {
					cout << x << ":" << y << ' ';
				}
				cout << '\n';
				return;
			}
		}
	}
	cout << "Impossible\n";
}
int main()
{
	//fastio;
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		solve();
	}
	
}