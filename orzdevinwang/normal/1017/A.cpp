#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, m, a[N], b[N], c[N], d[N], cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i] >> b[i] >> c[i] >> d[i], a[i] += b[i] + c[i] + d[i];
	L(i, 2, n) {
		if(a[1] < a[i]) cnt ++;
	}
	cout << cnt + 1 << endl;
	return 0;
}