//sobskdrbhvk
//remember the flying, the bird dies ):(
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
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxc = 26,
	  maxn = 1500 + 10;
int ans[maxc][maxn];
int n;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n
		>> s;
	for (char c = 'a'; c <= 'z'; c++) {
		vector<int> vec;
		vec.PB(-1);
		for (int i = 0; i < n; i++)
			if (s[i] != c)
				vec.PB(i);
		vec.PB(n);
		int id = c - 'a';
		for (int i = 0; i <= n; i++) {
			ans[id][i] = (i > 0 ? ans[id][i - 1] : 0);
			for (int j = i + 1; j < sz(vec); j++)
				smax(ans[id][i], vec[j] - vec[j - (i + 1)] - 1);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		char c;
		int cnt;
		cin >> cnt >> c;
		cout << ans[c - 'a'][cnt] << '\n';
	}
	return 0;
}