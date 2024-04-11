#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
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
	int a[N];
	int c[N];
	int l, r;
	char d[N];
	rep(i, N)d[i] = 0;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n)c[i] = 0;
		rep(i, n) {
			cin >> a[i];
			a[i]--;
			c[a[i]]++;
		}
		d[0] = '1';
		rep(i, n)if (c[i] != 1)d[0] = '0';
		l = 0;
		r = n - 1;
		rep(i, n - 1) {
			if (c[i] == 0) {
				rep2(j, 1, n - i - 1)d[j] = '0';
				break;
			}
			if (c[i] >= 2) {
				d[n - i - 1] = '1';
				rep2(j, 1, n - i - 2)d[j] = '0';
				break;
			}
			if ((a[l] != i) && (a[r] != i)) {
				d[n - i - 1] = '1';
				rep2(j, 1, n - i - 2)d[j] = '0';
				break;
			}
			if (a[l] == i)l++;
			else r--;
			d[n - i - 1] = '1';
		}
		cout << d << endl;
		rep(i, n + 1)d[i] = 0;

	}
	return 0;
}