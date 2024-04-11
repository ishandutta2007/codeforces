#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define dy second
#define dx first
#define PI pair<int, int>

using namespace std;
int gr[500][500][8] = {};
bool v[500][500] = {};
int of = 1;
std::vector<pair<PI, PI>> mk(8);
std::map<PI, int> m1;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	// print("here");
	vector<int> t(n); for (int o = 0; o < n; o++) { cin >> t[o]; }
	// print("here");
	mk[0] = {{1, 1}, { -1, 1}};
	mk[1] = {{1, 1}, {1, -1}};
	mk[2] = {{1, -1}, { -1, -1}};
	mk[3] = {{ -1, 1}, { -1, -1}};
	mk[4] = {{0, 1}, {1, 0}};
	mk[5] = {{0, -1}, {1, 0}};
	mk[6] = {{0, 1}, { -1, 0}};
	mk[7] = {{0, -1}, { -1, 0}};
	m1[ {0, 1}] = 0;
	m1[ {1, 0}] = 1;
	m1[ {0, -1}] = 2;
	m1[ { -1, 0}] = 3;
	m1[ {1, 1}] = 4;
	m1[ {1, -1}] = 5;
	m1[ { -1, 1}] = 6;
	m1[ { -1, -1}] = 7;
	std::vector<PI> pv = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};
	gr[250][250][0] = 1;
	int temp[500][500][8] = {};
	for (int o = 0; o < n; ++o) {
		for (int l = 0; l < t[o] - 1; ++l) {
			// print(of);
			for (int i = 0; i < 500; ++i)
				for (int j = 0; j < 500; ++j)
					for (int k = 0; k < 8; ++k)
						if (gr[i][j][k] == of) {
							v[i][j] = true;
							// print(i, j);
							temp[i + pv[k].dx][j + pv[k].dy][k] = of + 1;
							// print(i + pv[k].dx, j + pv[k].dy, k);
						}
			of++;
			for (int i = 0; i < 500; ++i)
				for (int j = 0; j < 500; ++j)
					for (int k = 0; k < 8; ++k)
						if (temp[i][j][k] == of)
							gr[i][j][k] = of;
		}
		for (int i = 0; i < 500; ++i)
			for (int j = 0; j < 500; ++j)
				for (int k = 0; k < 8; ++k)
					if (gr[i][j][k] == of) {
						auto p = mk[k];
						auto in = m1[pv[k]];
						// print(i, j);
						v[i][j] = true;
						temp[i + p.first.dx][j + p.first.dy][m1[p.first]] = of + 1;
						temp[i + p.second.dx][j + p.second.dy][m1[p.second]] = of + 1;
						// print(i + p.second.dx, j + p.second.dy, of + 1, m1[p.second]);
						// print(i + p.first.dx, j + p.first.dy, of + 1, m1[p.first]);
					}
		// print(of);
		of++;
		for (int i = 0; i < 500; ++i)
			for (int j = 0; j < 500; ++j)
				for (int k = 0; k < 8; ++k)
					if (temp[i][j][k] == of)
						gr[i][j][k] = of;
	}
	int c = 0;
	for (int i = 0; i < 500; ++i)
		for (int j = 0; j < 500; ++j)
			if (v[i][j]) c++;
	cout << c;
}