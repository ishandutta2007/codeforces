#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	if (N == 1) {
		cout << "? 1 1" << endl;
		string s;
		cin >> s;
		cout << "! " << s << endl;
		return 0;
	}
	if (N == 2) {
		cout << "? 1 1" << endl;
		string s, t;
		cin >> s;
		cout << "? 2 2" << endl;
		cin >> t;
		cout <<"! "<< s << t << endl;
		return 0;
	}
	if (N == 3) {
		cout << "? 1 1" << endl;
		string s, t, u;
		cin >> s;
		cout << "? 2 2" << endl;
		cin >> t;
		cout << "? 3 3" << endl;
		cin >> u;
		cout << "! " << s << t << u << endl;
		return 0;
	}
	if (N & 1) {
		cout << "? 1 " << N << endl;
		vector<vector<int>>a(N + 1, vector<int>(26));
		for (int i = 0; i < N*(N + 1) / 2; i++) {
			string s;
			cin >> s;
			for (auto i : s) {
				a[s.size()][i - 'a']++;
			}
		}
		cout << "? 1 " << N /2 << endl;
		vector<vector<int>>b(N + 1, vector<int>(26));
		for (int i = 0; i < (N/2)*(N/2+1)/2; i++) {
			string s;
			cin >> s;
			for (auto i : s) {
				b[s.size()][i - 'a']++;
			}
		}
		cout << "? " << N / 2+1<<" "<<N << endl;
		vector<vector<int>>c(N + 1, vector<int>(26));
		for (int i = 0; i < (N / 2 + 1)*(N / 2 + 2) / 2; i++) {
			string s;
			cin >> s;
			for (auto i : s) {
				c[s.size()][i - 'a']++;
			}
		}
		vector<vector<vector<int>>>cand(N, vector<vector<int>>(N));
		//vector<vector<int>>acand(N);
		auto add = a[1];
		for (int i = 2; i <= (N + 3) / 2; i++) {
			for (int j = 0; j < 26; j++) {
				if (a[i][j] < a[i - 1][j] + add[j]) {
					cand[i - 2][N - 1 - i + 2].push_back(j);
					//acand[i - 2].push_back(j);
					add[j] -= a[i - 1][j] + add[j] - a[i][j];
				}
			}
			if (cand[i - 2][N - 1 - i + 2].size() == 1)cand[i - 2][N - 1 - i + 2].push_back(cand[i - 2][N - 1 - i + 2].back());
			//if (acand[i - 2].size() == 1)acand[i - 2].push_back(acand[i - 2].front());
		}
		//vector<vector<int>>bcand(N);
		add = b[1];
		for (int i = 2; i <= (N + 5) / 4; i++) {
			for (int j = 0; j < 26; j++) {
				if (b[i][j] < b[i - 1][j] + add[j]) {
					//bcand[i - 2].push_back(j);
					cand[i - 2][N/2 - 1 - i + 2].push_back(j);
					add[j] -= b[i - 1][j] + add[j] - b[i][j];
				}
			}
			if (cand[i - 2][N/2 - 1 - i + 2].size() == 1)cand[i - 2][N/2 - 1 - i + 2].push_back(cand[i - 2][N/2 - 1 - i + 2].back());
			//if (bcand[i - 2].size() == 1)bcand[i - 2].push_back(bcand[i - 2].front());
		}
		//vector<vector<int>>ccand(N);
		add = c[1];
		for (int i = 2; i <= (N + 7) / 4; i++) {
			for (int j = 0; j < 26; j++) {
				if (c[i][j] < c[i - 1][j] + add[j]) {
					//ccand[i - 2].push_back(j);
					cand[i - 2+N/2][N/2+N / 2  - i + 2].push_back(j);
					add[j] -= c[i - 1][j] + add[j] - c[i][j];
				}
			}
			if (cand[i - 2 + N / 2][N / 2 + N / 2 - i + 2].size() == 1)cand[i - 2 + N / 2][N / 2 + N / 2 - i + 2].push_back(cand[i - 2 + N / 2][N / 2 + N / 2 - i + 2].back());
			//if (ccand[i - 2].size() == 1)ccand[i - 2].push_back(ccand[i - 2].front());
		}
		string ans(N, '0');
		for (int loop = 0; loop < N; loop++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (cand[i][j].empty())continue;
					if (i == j) {
						if (ans[i] == '0') {
							ans[i] = 'a' + cand[i][j][0];
						}
						continue;
					}
					if (ans[i] != '0') {
						if (cand[i][j][0] == ans[i] - 'a')ans[j] = 'a' + cand[i][j][1];
						else ans[j] = 'a' + cand[i][j][0];
					}
					else if (ans[j] != '0') {
						if (cand[i][j][0] == ans[j] - 'a')ans[i] = 'a' + cand[i][j][1];
						else ans[i] = 'a' + cand[i][j][0];
					}
				}
			}
		}
		cout <<"! "<< ans << endl;
		return 0;
	}
	else {
		cout << "? 1 " << N-1 << endl;
		vector<vector<int>>a(N + 1, vector<int>(26));
		for (int i = 0; i < N*(N - 1) / 2; i++) {
			string s;
			cin >> s;
			for (auto i : s) {
				a[s.size()][i - 'a']++;
			}
		}
		cout << "? 1 " << N / 2 << endl;
		vector<vector<int>>b(N + 1, vector<int>(26));
		for (int i = 0; i < (N / 2)*(N / 2 + 1) / 2; i++) {
			string s;
			cin >> s;
			for (auto i : s) {
				b[s.size()][i - 'a']++;
			}
		}
		cout << "? " << N / 2 + 1 << " " << N << endl;
		vector<vector<int>>c(N + 1, vector<int>(26));
		for (int i = 0; i < (N / 2)*(N / 2 + 1) / 2; i++) {
			string s;
			cin >> s;
			for (auto i : s) {
				c[s.size()][i - 'a']++;
			}
		}
		vector<vector<vector<int>>>cand(N, vector<vector<int>>(N));
		//vector<vector<int>>acand(N);
		auto add = a[1];
		for (int i = 2; i <= (N + 2) / 2; i++) {
			for (int j = 0; j < 26; j++) {
				if (a[i][j] < a[i - 1][j] + add[j]) {
					cand[i - 2][N - 1 - i + 1].push_back(j);
					//acand[i - 2].push_back(j);
					add[j] -= a[i - 1][j] + add[j] - a[i][j];
				}
			}
			if (cand[i - 2][N - 1 - i + 1].size() == 1)cand[i - 2][N - 1 - i + 1].push_back(cand[i - 2][N - 1 - i + 1].back());
			//if (acand[i - 2].size() == 1)acand[i - 2].push_back(acand[i - 2].front());
		}
		//vector<vector<int>>bcand(N);
		add = b[1];
		for (int i = 2; i <= (N + 6) / 4; i++) {
			for (int j = 0; j < 26; j++) {
				if (b[i][j] < b[i - 1][j] + add[j]) {
					//bcand[i - 2].push_back(j);
					cand[i - 2][N / 2 - 1 - i + 2].push_back(j);
					add[j] -= b[i - 1][j] + add[j] - b[i][j];
				}
			}
			if (cand[i - 2][N / 2 - 1 - i + 2].size() == 1)cand[i - 2][N / 2 - 1 - i + 2].push_back(cand[i - 2][N / 2 - 1 - i + 2].back());
			//if (bcand[i - 2].size() == 1)bcand[i - 2].push_back(bcand[i - 2].front());
		}
		//cout << "jo" << endl;
		//vector<vector<int>>ccand(N);
		add = c[1];
		for (int i = 2; i <= (N + 6) / 4; i++) {
			for (int j = 0; j < 26; j++) {
				if (c[i][j] < c[i - 1][j] + add[j]) {
					//ccand[i - 2].push_back(j);
					cand[i - 2 + N / 2][N / 2 + N / 2 - i + 1].push_back(j);
					add[j] -= c[i - 1][j] + add[j] - c[i][j];
				}
			}
			if (cand[i - 2 + N / 2][N / 2 + N / 2 - i + 1].size() == 1)cand[i - 2 + N / 2][N / 2 + N / 2 - i + 1].push_back(cand[i - 2 + N / 2][N / 2 + N / 2 - i + 1].back());
			//if (ccand[i - 2].size() == 1)ccand[i - 2].push_back(ccand[i - 2].front());
		}
		//cout << "hoe" << endl;
		string ans(N, '0');
		for (int loop = 0; loop < N; loop++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (cand[i][j].empty())continue;
					//if(loop==0)cout << i << " " << j << endl;
					if (i == j) {
						if (ans[i] == '0') {
							ans[i] = 'a' + cand[i][j][0];
						}
						continue;
					}
					if (ans[i] != '0') {
						if (cand[i][j][0] == ans[i] - 'a')ans[j] = 'a' + cand[i][j][1];
						else ans[j] = 'a' + cand[i][j][0];
					}
					else if (ans[j] != '0') {
						if (cand[i][j][0] == ans[j] - 'a')ans[i] = 'a' + cand[i][j][1];
						else ans[i] = 'a' + cand[i][j][0];
					}
				}
			}
		}
		cout << "! " << ans << endl;
		return 0;
	}
	
}