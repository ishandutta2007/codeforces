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

const int maxn = 1e6;
vector<int> vec[26];
bool mark[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	string s;
	cin >> n >> k
		>> s;
	for (int i = 0; i < n; i++)
		vec[s[i] - 'a'].PB(i);
	for (int i = 0; i < 26; i++)
		for (auto pos : vec[i])
			if (k) {
				mark[pos] = true;
				k--;
			}
	for (int i = 0; i < n; i++)
		if (!mark[i])
			cout << s[i];
	cout << endl;
	return 0;
}