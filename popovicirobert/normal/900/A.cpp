#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	cin >> n;
	int a = 0, b = 0;
	for(i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a += (x < 0);
		b += (x > 0);
	}

	cout << (min(a, b) > 1 ? "No" : "Yes");
	// 100

    return 0;
}