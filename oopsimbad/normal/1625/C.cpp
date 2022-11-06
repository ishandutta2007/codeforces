#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

ll dp[505][505];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, L, K; cin >> N >> L >> K;
    int loc[N+1], time[N+1];
    F0R(i, N) cin >> loc[i];
    F0R(i, N) cin >> time[i];
    loc[N] = L;

    FOR(i, 1, N+1) F0R(j, K+1) dp[i][j] = 2147483647;
    F0R(i, N) 
        F0R(j, K+1)
            FOR(k, i+1, N+1) {
                if(k-i-1 + j > K) break;
                dp[k][k-i-1 + j] = min(dp[k][k-i-1 + j], dp[i][j] + (loc[k]-loc[i]) * time[i]);
            }

    ll best = 2147483647;
    F0R(i, K+1) best = min(best, dp[N][i]);
    cout << best << endl;

	return 0;
}