//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e5 + 10;
const LL Mod = 1000 * 1000 * 1000 + 7;
LL P[maxn];
string s;
int n, q;
int sum[maxn];

LL get(LL one, LL len) {
	LL zer = len - one;
	LL result = 0;
	result += (P[one] - 1) * (P[zer]);
	result %= Mod;
	result = (result + Mod) % Mod;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	P[0] = 1;
	for (int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] << 1) % Mod;
	cin >> n >> q;
	cin >> s;
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + (s[i] == '1');
	while(q--) {
		int fi, se;
		cin >> fi >> se;
		fi--;
		cout << get(sum[se] - sum[fi], se - fi) << '\n';
	}
	return 0;
}