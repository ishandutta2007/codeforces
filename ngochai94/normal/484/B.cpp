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

int n, ans, val, lis[2000006];
// set<int> s;
int bef[2000006];

int main() {
    ios::sync_with_stdio(0);
    // cin >> n;
    scanf("%d", &n);
    // n = 200000;
    while (n--) {
        // cin >> val;
        scanf("%d", &val);
        // val = 200000 - n;
        lis[val] = 1;
    }
    bef[0] = 0;
    FOR (i, 1, 2000004) {
        if (lis[i - 1]) bef[i] = i - 1;
        else bef[i] = bef[i - 1];
    }
    // for (int i: s) {
    FOR (i, 1, 1000000) if (lis[i]) {
        for (int j = i * 2; j < 2000006; j += i) {
            int tmp = bef[j];
            ans = max(ans, tmp % i);
        }
    }
    cout << ans;
}