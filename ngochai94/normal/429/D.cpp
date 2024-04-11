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

long long n, val, pre[100005];
pair<long long, long long> p[100005];

long long dis(long long x, long long y) {
    return (x - y) * (x - y) + (pre[x] - pre[y]) * (pre[x] - pre[y]); 
}

long long solve(long long st, long long en) {
    if (en - st == 0) return (1ll << 55);
    if (en - st == 1) return dis(st, en);
    long long mid = (st + en) / 2;
    long long bound = min(solve(st, mid), solve(mid + 1, en));
    long long cur = mid - 1;
    long long tot = 0;
    p[tot++] = {pre[mid], mid};
    while (cur >= st) {
        if ((cur - mid) * (cur - mid) > bound) break;
        p[tot++] = {pre[cur], cur};
        cur--;
    }
    cur = mid + 1;
    while (cur <= en) {
        if ((cur - mid) * (cur - mid) > bound) break;
        p[tot++] = {pre[cur], cur};
        cur++;
    }
    sort(p, p + tot);
    REP (i, tot) FOR (j, i + 1, min((long long)i + 7, tot - 1)) bound = min(bound, dis(p[i].second, p[j].second));
    return bound;
}

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, n) {
        cin >> val;
        pre[i] = pre[i - 1] + val;
        // BUG(pre[i]);
    }
    cout << solve(1ll, n);
}