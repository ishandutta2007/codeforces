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
	cout << "? 1 " << N << endl;
	vector<vector<int>>a(N + 1, vector<int>(26));
	for (int i = 0; i < N*(N + 1) / 2; i++) {
		string s;
		cin >> s;
		for (auto i : s) {
			a[s.size()][i - 'a']++;
		}
	}
	cout << "? 1 " << N - 1 << endl;
	vector<vector<int>>b(N + 1, vector<int>(26));
	for (int i = 0; i < N*(N - 1) / 2; i++) {
		string s;
		cin >> s;
		for (auto i : s) {
			b[s.size()][i - 'a']++;
		}
	}
	cout << "? 1 1" << endl;
	string s;
	cin >> s;
	int num = s[0] - 'a';
	vector<int>p(N);
	vector<vector<int>>cand(N);
	auto add = a[1];
	for (int i = 2; i <= (N + 3) / 2; i++) {
		for (int j = 0; j < 26; j++) {
			if (a[i][j] < a[i - 1][j] + add[j]) {
				cand[i - 2].push_back(j);
				add[j] -= a[i - 1][j] + add[j] - a[i][j];
			}
		}
		if (cand[i - 2].size() == 1)cand[i - 2].push_back(cand[i - 2].front());
	}
	vector<vector<int>>bcand(N);
	add = b[1];
	for (int i = 2; i <= (N + 2) / 2; i++) {
		for (int j = 0; j < 26; j++) {
			if (b[i][j] < b[i - 1][j] + add[j]) {
				bcand[i - 2].push_back(j);
				add[j] -= b[i - 1][j] + add[j] - b[i][j];
			}
		}
		if (bcand[i - 2].size() == 1)bcand[i - 2].push_back(bcand[i - 2].front());
	}

	//cout << "acand" << endl;
	//for (int i = 0; i < N; i++) {
	//	cout << i;
	//	for (auto j : cand[i])cout << " " << char(j + 'a');
	//	cout << endl;
	//}
	//cout << "bcand" << endl;
	//for (int i = 0; i < N; i++) {
	//	cout << i;
	//	for (auto j : bcand[i])cout << " " << char(j + 'a');
	//	cout << endl;
	//}
	string ans(N, '0');
	ans[0] = num + 'a';
	if (char(cand[0][0] + 'a') == ans[0])ans.back() = cand[0][1] + 'a';
	else ans.back() = cand[0][0] + 'a';
	for (int i = 1; i <= (N - 1) / 2; i++) {
		if (char(bcand[i - 1][0] + 'a') == ans[i - 1])ans[N - 1 - i] = bcand[i - 1][1] + 'a';
		else ans[N - 1 - i] = bcand[i - 1][0] + 'a';
		if (char(cand[i][0] + 'a') == ans[N - i - 1])ans[i] = cand[i][1] + 'a';
		else ans[i] = cand[i][0] + 'a';
	}
	cout << "! " << ans << endl;
}