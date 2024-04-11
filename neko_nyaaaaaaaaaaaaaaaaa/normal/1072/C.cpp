#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll a, b, x; cin >> a >> b;
	for (x = 80000; x*(x+1)/2 > a+b; x--);

	vector<int> ans1, ans2;
	for (int i = x; i; i--) {
            if (i <= a) {
                  ans1.push_back(i);
                  a -= i;
            } else {
                  ans2.push_back(i);
                  b -= i;
            }
	}

	cout << ans1.size() << '\n';
	for (int i: ans1) cout << i << ' ';
	cout << '\n' << ans2.size() << '\n';
	for (int i: ans2) cout << i << ' ';

	return 0;
}