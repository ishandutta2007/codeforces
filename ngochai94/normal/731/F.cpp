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

long long ans, n, cnt[200005], val;

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) {
        cin >> val;
        cnt[val]++;
    }
    FOR (i, 1, 200002) cnt[i] += cnt[i - 1];
    FOR (i, 1, 200002) if (cnt[i] > cnt[i - 1]) {
        long long cur = 0;
        for (int j = i; j < 200001; j += i) cur += (cnt[min(200002, j + i - 1)] - cnt[j - 1]) * j;
        ans = max(ans, cur);
    }
    cout << ans;
}