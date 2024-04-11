
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
ll modpow(ll a, ll b, ll md) { ll res = 1; a %= md; for (; b; b >>= 1) { if (b & 1)res = res * a%md; a = a * a%md; }return res; }


const ll m = 1e9 + 7, p = 33;
const int MAX_SIZE = 5000;
ll pows[MAX_SIZE], invpows[MAX_SIZE], table[MAX_SIZE];
string str;
bool dp[MAX_SIZE][MAX_SIZE], prv[MAX_SIZE][MAX_SIZE];
void compTable() {
	ll tmp;
	for (int i = 0; i < str.length(); i++) {
		tmp = (pows[i] * (str[i] - 'a' + 1)) % m; //CHANGE
		if (!i)table[i] = tmp;
		else table[i] = (table[i - 1] + tmp) % m;
	}
}
void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (!i)pows[i] = 1;
		else pows[i] = (pows[i - 1] * p) % m;
	}
	invpows[MAX_SIZE - 1] = modpow(pows[MAX_SIZE - 1], m - 2, m);
	for (int i = MAX_SIZE - 2; i >= 0; i--)invpows[i] = (invpows[i + 1] * p) % m;
	compTable();
}
ll sub(int i, int j) {
	if (i > j)return -1;
	if (!i)return table[j];
	return ((table[j] - table[i - 1] + m) *invpows[i]) % m;
}


int main() {
	fast;
	cin >> str;
	int n = str.length(), cnt = 0;
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; i - j >= 0 && i + j < n; j++) {
			if (str[i - j] == str[i + j]) {
				cnt++;
				prv[i - j][i + j] = 1;
			}
			else break;
		}
		if (i) {
			for (int j = 0; i - j - 1 >= 0 && i + j < n; j++) {
				if (str[i - j - 1] == str[i + j]) {
					cnt++;
					prv[i - j - 1][i + j] = 1;
				}
				else break;
			}
		}
	}
	int cur = 1;
	cout << cnt << " ";
	while (cnt) {
		cur++;
		cnt = 0;
		foru(i, 0, n) {
			foru(j, i + 1, n) {
				int amt = (j - i + 1) / 2, l = i + amt - 1, r = j - amt + 1;
				if (prv[i][l] && prv[r][j] && sub(i, l) == sub(r, j)) {
					dp[i][j] = 1;
					cnt++;
				}
			}
		}
		cout << cnt << " ";
		foru(i, 0, n) {
			foru(j, 0, n) {
				prv[i][j] = dp[i][j];
				dp[i][j] = 0;
			}
		}
	}
	for (int j = cur; j < n; j++)cout << 0 << " ";
	cout << endl;
	return 0;
}