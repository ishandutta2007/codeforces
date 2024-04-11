#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

long long n, l, s, lis[100005], bef[100005], dp[100005];

multiset<long long> ms;

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> s >> l;
    FOR (i, 1, n) cin >> lis[i];
    FOR (i, 1, l) ms.insert(lis[i]);
    auto fi = ms.begin();
    auto en = ms.end();
    en--;
    if ((*en) - (*fi) > s) {
        cout << -1;
        return 0;
    }
    reset(dp, 55);
    dp[l] = 1;
    dp[0] = 0;
    bef[l] = 1;
    long long cur = 1;
    FOR (i, l + 1, n) {
        ms.insert(lis[i]);
        while (1) {
            auto fi = ms.begin();
            auto en = ms.end();
            en--;
            // cout << *fi << *en << s <<endl;
            if ((*en) - (*fi) <= s) {
                break;
            }
            ms.erase(ms.find(lis[cur++]));
        }
        bef[i] = cur;
        // cout << i << ' ' << bef[i] << endl;
    }
    // if (n == 2559) BUG("DONE");
    ms.clear();
    cur = 1;
    ms.insert(0);
    FOR (i, l + 1, n) {
        // if (n == 2559 && i >100) cout << i << ' ' << bef[i] << endl;
        ms.insert(dp[i - l]);
        while (cur < bef[i] && !ms.empty()) {
            ms.erase(ms.find(dp[cur - 1]));
            cur++;
            // if (n == 2559 && i == 106) cout << cur << ' ';
        }
        // if (n == 2559 && i >100) cout << i << endl;
        // cout << "MS: "; for (auto z: ms) cout << z << ' ' ;cout << endl;
        if (!ms.empty()) dp[i] = min(dp[i], *(ms.begin()) + 1);
        // cout << i << ' ' << dp[i] << endl;
    }
    if (dp[n] < mod) cout << dp[n];
    else cout << -1;
}