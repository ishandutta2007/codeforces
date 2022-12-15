#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

long long n, lis[5555];

long long solve(long long l, long long r, long long reduce) {
    long long cur = lis[l];
    FOR (i, l + 1, r) cur = min(cur, lis[i]);
    long long ans = cur - reduce;
    long long ll = -1;
    FOR (i, l, r) {
        if (lis[i] == cur) {
            if (ll != -1) {
                ans += solve(ll, i - 1, cur);
                ll = -1;
            }
        } else if (ll == -1) ll = i;
    }
    if (ll != -1) ans += solve(ll, r, cur);
    return min(ans, r - l + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    cout << solve(0, n - 1, 0);
}