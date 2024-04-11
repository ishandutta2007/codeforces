#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, ans = 0;
bool e[26][26];
int loc[26][26];
string s1, s2;

int main() {
	fast;
	for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) e[i][j] = false;
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++)
		if (s1[i] != s2[i])
			e[s1[i] - 'a'][s2[i] - 'a'] = true, loc[s1[i] - 'a'][s2[i] - 'a'] = i, ans++;
	for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++)
		if (e[i][j] && e[j][i]) {
			cout << ans - 2 << endl << loc[i][j] + 1 << " " << loc[j][i] + 1 << endl;
			return 0;
		}
	for (int i = 0; i < 26; i++) {
		bool r = false, c = false;
		int j1, j2;
		for (j1 = 0; j1 < 26 && !r; j1++)
			if (i != j1)
				r = r || e[i][j1];
		j1--;
		for (j2 = 0; j2 < 26 && !c; j2++)
			if (i != j2)
				c = c || e[j2][i];
		j2--;
		if (r && c) {
			cout << ans - 1 << endl << loc[i][j1] + 1 << " " << loc[j2][i] + 1 << endl;
			return 0;
		}
	}
	cout << ans << endl << "-1 -1" << endl;
	return 0;
}