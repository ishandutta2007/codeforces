#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;



int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int i, n;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string str; cin >> n >> str;
	vector<int> sp(n + 1);
	for(i = 1; i <= n; i++) {
		sp[i] = sp[i - 1] + (str[i - 1] == '(' ? 1 : -1);
	}
	int ans = 0, last = 0;
	bool ok = 1;
	for(i = 1; i <= n; i++) {
		if(sp[i] < 0) {
			ok = 0;
		} 
		if(sp[i] == 0) {
			if(ok == 0) {
				ans += i - last;
			}
			ok = 1, last = i; 
		}
	}
	if(sp[n] != 0 || ok == 0) {
		ans = -1;
	}
	cout << ans;

	return 0;
}