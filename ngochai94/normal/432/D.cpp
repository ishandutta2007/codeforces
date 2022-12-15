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

int n, kmp[100005], ans[100005];
string s;

int main(){
    ios::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    kmp[0] = -1;
    kmp[1] = 0;
    int cur = 0;
    FOR (i, 2, n) {
        while (cur >= 0 && s[cur] != s[i - 1]) cur = kmp[cur];
        cur++;
        kmp[i] = cur;
        ans[cur]++;
        // cout << i << ' ' << kmp[i] << endl;
    }
    ans[n] = 1;
    FORD (i, n, 1) {
        ans[kmp[i]] += ans[i];
    }
    cur = n;
    int tot = 0;
    while (cur > 0) {
        ans[cur] = -ans[cur];
        tot++;
        cur = kmp[cur];
    }
    cout << tot << endl;
    FOR (i, 1, n) if (ans[i] < 0) cout << i << ' ' << -ans[i]<< endl;
}