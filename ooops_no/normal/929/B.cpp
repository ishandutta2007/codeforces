#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

#define pb push_back

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, k;
	cin >> x >> k;
	vector < vector < char > > g(x, vector < char >(12));
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < 12; j++) {
			cin >> g[i][j];
			
		}
	}
	int cntb = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < 12; j++) {
			int cnt = 0;
			if (g[i][j] == '.') {
				if (j - 1 >= 0) {
					if (g[i][j - 1] == 'S') {
						cnt++;
					}
				}
				if (j + 1 < 12) {
					if (g[i][j + 1] == 'S') {
						cnt++;
					}
				}
				v.pb(make_pair(cnt, make_pair(i, j)));
				continue;
			}
			if (g[i][j] == 'S') {
				if (j - 1 >= 0) {
					if (g[i][j - 1] != '.' && g[i][j-1] != '-') {
						cntb++;
					}
				}
				if (j + 1 < 12 ) {
					if (g[i][j + 1] != '.' && g[i][j+1] != '-') {
						cntb++;
					}
				}
			}
		}
	}
	sort(v.begin(), v.end());
	for (auto to : v) {
		if (k == 0) {
			break;
		}
		else {
			int i = to.second.first, j = to.second.second;
			cntb += to.first;
			g[i][j] = 'x';
			k--;
		}
	}
	cout <<  cntb << endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < 12; j++) {
			cout << g[i][j];
		}
		cout << endl;
	}
}