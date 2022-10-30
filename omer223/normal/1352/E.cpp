#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define has(set, x) set.find(x) != set.end()
#define us unordered_set
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <bitset>
using namespace std;

int n;
short a[8001];
bitset<8001> ans;
int pref[8001];
short q(int a, int b) {
	int ans;
	if (!a) ans = (int)pref[b];
	else ans = (int)pref[b] - (int)pref[a - 1];
	if (ans > n) return -1;
	return (short)ans;
}
void ms(int n) {
	foru(i, 1, n + 1)ans[i] = 0;
}
int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		foru(i, 0, n) {
			cin >> a[i];
			if (!i)pref[i] = a[i];
			else pref[i] = pref[i - 1] + a[i];
		}
		int cnt = 0;
		foru(i, 0, n-1) {
			foru(j, i + 1, n) {
				short tmpQ = q(i, j);
				if(tmpQ>0)ans[tmpQ] = 1;
			}
		}
		foru(i, 0, n) {
			if (ans[a[i]])cnt++;
		}
		cout << cnt << endl;
		ms(n);
	}
	return 0;
}