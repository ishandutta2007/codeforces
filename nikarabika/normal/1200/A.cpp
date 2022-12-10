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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[10] = {0};
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L')
			for (int i = 0; i < 10; i++) {
				if (!a[i]) {
					a[i] = 1;
					break;
				}
			}
		else if (s[i] == 'R')
			for (int i = 9; ~i; i--) {
				if (!a[i]) {
					a[i] = 1;
					break;
				}
			}
		else
			a[s[i] - '0'] = 0;
	}
	for (int i = 0; i < 10; i++)
		cout << a[i];
	cout << endl;
	return 0;
}