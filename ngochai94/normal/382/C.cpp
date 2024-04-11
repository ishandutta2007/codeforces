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

int n, lis[100005];
set<int> s, ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    sort(lis, lis + n);
    if (n == 1) {
        cout << -1;
        return 0;
    }
    if (n == 2) {
        ans.insert(2 * lis[1] - lis[0]);
        ans.insert(2 * lis[0] - lis[1]);
        if ((lis[0] + lis[1]) % 2 == 0) ans.insert((lis[0] + lis[1]) / 2);
        cout << ans.size() << endl;
        for (auto i: ans) cout << i << ' ' ;
        return 0;
    }
    FOR (i, 0, n - 2) s.insert(lis[i + 1] - lis[i]);
    if (s.size() == 1) {
        int ran = *s.begin();
        ans.insert(lis[0] - ran);
        ans.insert(lis[n -  1] + ran);
    } else if (s.size() == 2) {
        int ran1 = *s.begin();
        int ran2 = *(++s.begin());
        if (ran1 * 2 == ran2) {
            REP (i, n - 1) if (lis[i + 1] - lis[i] == ran2) ans.insert(lis[i] + ran1);
            if (ans.size() > 1) ans.clear();
        }
    }
    cout << ans.size() << endl;
    for (auto i: ans) cout << i << ' ';
}