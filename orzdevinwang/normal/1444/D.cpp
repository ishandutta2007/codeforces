#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1024;
bitset < N * N > dp[N];
int n, rn, h[N], p[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> h[i];
	cin >> rn;
	L(i, 1, rn) cin >> p[i];
	if(n != rn) return cout << "No\n", void ();
	int sum = 0, ms = 0, cnt = 0;
	L(i, 1, n) sum += h[i], dp[i] = dp[i - 1] | (dp[i - 1] << h[i]);
	if((sum & 1) || !dp[n][sum / 2]) return cout << "No\n", void ();
	ms = sum / 2;
	R(i, n, 1) if(!dp[i - 1][ms]) ms -= h[i], h[i] = -h[i], cnt += 1;
	if(cnt <= n / 2) L(i, 1, n) h[i] = -h[i]; 
	
	sum = 0, cnt = 0;
	L(i, 1, n) sum += p[i], dp[i] = dp[i - 1] | (dp[i - 1] << p[i]);
	if((sum & 1) || !dp[n][sum / 2]) return cout << "No\n", void ();
	ms = sum / 2;
	R(i, n, 1) if(!dp[i - 1][ms]) ms -= p[i], p[i] = -p[i], cnt += 1;
	if(cnt > n / 2) L(i, 1, n) p[i] = -p[i]; 
	
	sort(h + 1, h + n + 1, [&] (int x, int y) { return x > y; });
	sort(p + 1, p + n + 1, [&] (int x, int y) { return x > y; });
	int M = n + 1;
	L(i, 1, n) if(p[i] > 0) M = i;
	reverse(p + 1, p + M + 1);
	M = 0;
	L(i, 1, n) if(h[i] > 0) M = i;
	reverse(h + M + 1, h + n + 1);
	int X = 0, Y = 0;
	cout << "Yes\n";
	L(i, 1, n) {
		cout << X << ' ' << Y << '\n';
		X += h[i];
		cout << X << ' ' << Y << '\n';
		Y += p[i];	
	}
}
int main () {
	dp[0].set (0);
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}