#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

string s;
int p[10000000];
map<char, char> rev;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	rev['{'] = '}';
	rev['<'] = '>';
	rev['('] = ')';
	rev['['] = ']';
	rev['}'] = '{';
	rev['>'] = '<';
	rev[')'] = '(';
	rev[']'] = '[';

	cin >> s;

	stack<int> opened;

	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '<' || s[i] == '{' || s[i] == '(' || s[i] == '[') {
			opened.push(i);
		} else {
			if (sz(opened) == 0) {
				cout << "Impossible\n";
				return 0;
			}

			int x = opened.top();
			opened.pop();
			p[x] = i;
			p[i] = x;
		}
	}

	if (sz(opened) != 0) {
		cout << "Impossible\n";
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < sz(s); i++) {
		if (rev[s[p[i]]] != s[i]) {
			ans++;
		}
	}

	cout << ans / 2 << "\n";

    return 0;
}