#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int
using namespace std;
const int N = 1007;
int n, m, a[N][N];
ll s[N], W[N], rk[N], ns1, dt;
vi iq;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0); 
	cin >> m >> n;
	L(i, 1, n) L(j, 1, m) 
		cin >> a[i][j], s[i] += a[i][j], W[i] += (ll) a[i][j] * a[i][j];
	L(i, 2, n) 
		rk[i] = s[i] - s[i - 1];
	ll ts = -1;
	L(i, 2, n) if(ts == -1) L(j, 2, i - 1) if(ts == -1) L(k, 2, j - 1) if(rk[i] == rk[j] && rk[j] == rk[k]) {
		ts = rk[i];
		break ;
	}
	L(i, 2, n) if(rk[i] != ts) iq.push_back(i);
	if(sz(iq) == 1 && iq[0] == 2) ns1 = 1;
	else ns1 = iq[0];
	if(ns1 <= 2) dt = rk[ns1 + 2] - rk[ns1 + 1];
	else dt = rk[ns1] - rk[ns1 - 1];
	ll cm = W[3] - 2 * W[2] + W[1], nk = 0;
	if(ns1 <= 3) cm = W[6] - 2 * W[5] + W[4];
	if(ns1 <= 3) nk = cm + 2 * W[ns1 + 1] - W[ns1 + 2];
	else nk = cm + 2 * W[ns1 - 1] - W[ns1 - 2];
	cout << ns1 - 1 << ' ' << ((W[ns1] - nk) / dt - dt) / 2 << '\n';
	return 0;
}