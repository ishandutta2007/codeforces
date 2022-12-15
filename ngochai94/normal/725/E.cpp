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

int n, c, cnt[200005], val, below[200005];

bool ok(int x) {
    int cur = c;
    int tot = c;
    while (tot) {
        // BUG(tot);
        int tmp = below[cur];
        if (!tmp) return true;
        // BUG(tmp);
        if (tmp <= x && x <= tot) {
            tot -= x;
            x = 0;
            cur = min(cur, tot);
        } else {
            tot -= min(tot / tmp, cnt[tmp]) * tmp;
            cur = min(tmp - 1, tot);
        }
        
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin >> c >> n;
    REP (i, n) {
        cin >> val;
        cnt[val]++;
    }
    FOR (i, 1, 200000) {
        if (cnt[i]) below[i] = i;
        else below[i] = below[i - 1];
    }
    // cout << cnt[2] << endl;
    // cout << ok(1);return 0;
    FOR (i, 1, c - 1) if (ok(i)) {
        cout << i;
        return 0;
    }
    cout << "Greed is good";
}