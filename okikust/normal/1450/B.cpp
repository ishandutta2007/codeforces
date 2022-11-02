#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 110
#define M 200100
#define MOD 1000000007 //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main(void){
	int t, n, k;
	int xx[N];
	int yy[N];
	bool v;

	cin >> t;
	rep(tt, t) {
		cin >> n >> k;
		rep(i, n) {
			cin >> xx[i] >> yy[i];
		}
		rep(i, n) {
			v = true;
			rep(j, n) {
				if ((abs(xx[i] - xx[j]) + abs(yy[i] - yy[j])) > k) {
					v = false;
					break;
				}
			}
			if (v)break;
		}
		if (v)cout << 1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}