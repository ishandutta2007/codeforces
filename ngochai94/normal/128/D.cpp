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

int n, lis[100005], m, cnt[100005];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    m = mod;
    REP (i, n) {
        cin >> lis[i];
        m = min(m, lis[i]);
    }
    REP (i, n) {
        if (lis[i] - m >= n) {
            cout << "NO";
            return 0;
        }
        cnt[lis[i] - m]++;
    }
    bool flag = false;
    FOR (i, 1, n) {
        cnt[i] -= cnt[i - 1];
        // cout << i << ' ' << cnt[i] << endl;
        if (cnt[i] < 0 || flag && cnt[i]) {
            cout << "NO";
            return 0;
        }
        if (!cnt[i]) flag = true;
    }
    if (cnt[n]) cout << "NO";
    else cout << "YES";
}