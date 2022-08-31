#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 7;
int n, m;
ll a[N], d[N], b[N], sum, ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i] >> b[i], sum += a[i];
	if(sum < 0) L(i, 1, n) a[i] = -a[i];
	L(i, 0, 61) {
		ll sum = 0;
		L(j, 1, n) if(((b[j] >> i) & 1) && b[j] < (1LL << (i + 1))) sum += a[j];
		if(sum > 0) {
			ans |= (1LL << i);
			L(j, 1, n) if((b[j] >> i) & 1) a[j] = -a[j];
		}
	}
	cout << ans << endl;
	return 0;
}