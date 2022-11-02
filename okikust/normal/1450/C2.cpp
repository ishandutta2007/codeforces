#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 310
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
	char a[N][N];
	int co, cx, vcm;
	int b[N][N];
	int d[3];
	int e[3];
	rep(i, N) {
		rep(j, N) {
			b[i][j] = (i + j) % 3;
		}
	}

	cin >> t;
	rep(tt, t) {
		rep(i, N) {
			rep(j, N)a[i][j] = 0;
		}
		cin >> n;
		rep(i, n)cin >> a[i];
		rep(i, 3) {
			d[i] = 0;
			e[i] = 0;
		}
		rep(i, n) {
			rep(j, n) {
				if (a[i][j] == 'O') {
					d[b[i][j]]++;
				}
				else if (a[i][j] == 'X') {
					e[b[i][j]]++;
				}
			}
		}
		vcm = 100000000;
		rep(i, 3) {
			rep(j, 3) {
				if (i != j) {
					if ((d[i] + e[j]) < vcm) {
						vcm = d[i] + e[j];
						co = i;
						cx = j;
					}
				}
			}
		}
		rep(i, n) {
			rep(j, n) {
				if ((b[i][j] == co) && (a[i][j] == 'O'))a[i][j] = 'X';
				if ((b[i][j] == cx) && (a[i][j] == 'X'))a[i][j] = 'O';
			}
		}
		rep(i, n)cout << a[i] << endl;

	}
	return 0;
}