#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, m, ans, lis[10], used[10], l, l1, l2;
long long cur;

bool check() {
    long long ret = 0;
    cur = 1;
    REP (i, l1) {
        ret += cur * lis[i];
        cur *= 7;
    }
    if (ret >= n) return false;
    ret = 0;
    cur = 1;
    REP (i, l2) {
        ret += cur * lis[i + l1];
        cur *= 7;
    }
    // if (ret < m) {
    //     REP (i, l) cout << lis[i] << ' ';
    //     cout << endl;
    // }
    return ret < m;
}

void solve(int x) {
    if (x == l) {
        if (check()) ans++;
        return;
    }
    REP (i, 7) if (!used[i]) {
        used[i] = 1;
        lis[x] = i;
        solve(x + 1);
        used[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    l1 = 1;
    cur = 7;
    while (cur < n) {
        cur *= 7;
        l1++;
    }
    l2 = 1;
    cur = 7;
    while (cur < m) {
        cur *= 7;
        l2++;
    }
    l = l1 + l2;
    if (l > 7) {
        cout << 0;
        return 0;
    }
    solve(0);
    cout << ans;
}