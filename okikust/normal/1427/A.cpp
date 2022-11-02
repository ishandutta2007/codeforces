#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define N 110
#define MOD 998244353 //1000000007
#define pll pair<ll,ll>


int main() {
	int n, m, k;
	int x, y, z;
	int s, ans;
	int a[N];
	cin >> k;
	rep(kk, k) {
		cin >> n;
		s = 0;
		rep(i, n) {
			cin >> a[i];
			s += a[i];
		}
		if (s == 0) {
			cout<<"NO"<<endl;
			continue;
		}if (s > 0) {
			cout << "YES" << endl;
			sort(a, a + n, greater<int>());
			rep(i, n - 1) {
				cout << a[i] << " ";
			}
			cout << a[n - 1] << endl;
		}
		else {
			cout << "YES" << endl;
			sort(a, a + n);
			rep(i, n - 1) {
				cout << a[i] << " ";
			}
			cout << a[n - 1] << endl;
		}

	}

	return 0;
}