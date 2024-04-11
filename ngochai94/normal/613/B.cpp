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

long long n, lis[100005], A, cf, cm, m, ini[100005];
pair<long long, int> assist[100005];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> A >> cf >> cm >> m;
    REP (i, n) cin >> lis[i];
    REP (i, n) ini[i] = lis[i];
    REP (i, n) assist[i] = {lis[i], i};
    sort(assist, assist + n);
    sort(lis, lis + n);
    long long cur = m;
    int pt = n - 1;
    while (pt >= 0 && cur >= A - lis[pt]) {
        cur -= A - lis[pt--];
    }
    if (pt == -1) {
        cout << n * cf + cm * A << endl;
        REP (i, n) cout << A << ' ';
        return 0;
    }
    int l = 0;
    while (l < pt) {
        long long need = (l + 1) * (lis[l + 1] - lis[l]);
        if (cur >= need) {
            cur -= need;
            l++;
        } else break;
    }
    long long ans = cf * (n - 1 - pt) + cm * (lis[l] + cur / (l + 1));
    int anspt = pt;
    int ansl = l;
    int ansmin = lis[l] + cur / (l + 1);
    while (pt < n - 1) {
        pt++;
        cur += A - lis[pt];
        while (l < pt) {
            long long need = (l + 1) * (lis[l + 1] - lis[l]);
            if (cur >= need) {
                cur -= need;
                l++;
            } else break;
        }
        if (ans < cf * (n - 1 - pt) + cm * (lis[l] + cur / (l + 1))) {
            anspt = pt;
            ansl = l;
            ansmin = lis[l] + cur / (l + 1);
        }
        ans = max(ans, cf * (n - 1 - pt) + cm * (lis[l] + cur / (l + 1)));
    }
    cout << ans << endl;
    pt = anspt;
    l = ansl;
    FOR (i, pt + 1, n - 1) ini[assist[i].second] = A;
    FOR (i, 0, l) ini[assist[i].second] = ansmin;
    REP (i, n) cout << ini[i] << ' ';
}