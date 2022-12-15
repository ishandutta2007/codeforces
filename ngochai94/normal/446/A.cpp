#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

int n, lis[100005], pre[100005], ans, aft[100005];

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    pre[0] = 0;
    FOR (i, 1, n - 1) pre[i] = (lis[i - 1] < lis[i]) ? pre[i - 1] : i;
    aft[n - 1] = n - 1;
    FORD(i, n - 2, 0) aft[i] = (lis[i] < lis[i + 1]) ? aft[i + 1] : i;
    ans = 1;
    if (n > 1) ans = 1 + max(aft[1], n - pre[n - 2] - 1);
    FOR (i, 1, n - 2) {
        int cur = 0;
        if (lis[i + 1] - lis[i - 1] > 1) cur = aft[i + 1] - pre[i - 1] + 1;
        else cur = max(i - pre[i - 1], aft[i + 1] - i) + 1;
        ans = max(ans, cur);
    }
    cout << ans;
}