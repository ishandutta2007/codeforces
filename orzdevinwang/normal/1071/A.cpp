#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, f[N], A[N], B[N], tota, totb;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int sum = n + m, now = 1;
	while(sum >= now) {
		sum -= now;
		++now;
	}
	--now;
	R(i, now, 1) {
		if(n >= i) {
			n -= i;
			A[++tota] = i;
		}
		else B[++totb] = i;
	}
	cout << tota << endl;
	L(i, 1, tota) cout << A[i] << " ";
	cout << endl;
	cout << totb << endl;
	L(i, 1, totb) cout << B[i] << " ";
	cout << endl;
    return 0;
}