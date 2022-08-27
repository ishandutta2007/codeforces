#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 19, fn = 1e5, mod = 998244353;
int n, k;	
ll phi[N], h[N], dp[N][20];
bool Prime[N];
int p[N >> 3], tot;
void xxs(int x) {
	phi[1] = 1;
    L(i, 2, x) {
        if(!Prime[i]) p[++tot] = i, phi[i] = i - 1;
        for(int j = 1; j <= tot && p[j] * i <= x; j++) {
            Prime[p[j] * i] = 1;
            if(i % p[j] == 0) {
            	phi[i * p[j]] = phi[i] * p[j];
            	break ;
			}
			phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
    L(i, 1, x) h[i] = h[i - 1] + phi[i];
}
int ck;
void divide (int l, int r, int jl, int jr) { // added 
	if (l > r) return ;
	int mid = (l + r) >> 1, rmid = -1;
	ll qry = 0;
	for (int l = jl, r; l <= mid; l = r + 1) 
		r = mid / (mid / l), qry += h[mid / l] * (r - l + 1);
	L(l, jl, min(jr, mid)) {
		ll sum = dp[l - 1][ck - 1] + qry;
		qry -= h[mid / l];
		if(sum < dp[mid][ck]) rmid = l, dp[mid][ck] = sum;
	}
	if(rmid == -1) assert (0);
	divide (mid + 1, r, rmid, jr);
	divide (l, mid - 1, jl, rmid);
}
void Main () {
	cin >> n >> k;
	if (k > 17) {
		cout << n << '\n';
		return ;
	}
	cout << dp[n][k] << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	xxs (fn);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	L(i, 1, 17) ck = i, divide (i, fn, 1, fn);
	int T;
	cin >> T ;
	while (T--) Main (); 
	return 0;
}