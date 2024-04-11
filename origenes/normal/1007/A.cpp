#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123456;

int n, a[maxn];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    sort(a, a+n);
    int p1 = 0, ans = 0;
    REP(p2, n) {
        if (a[p2] > a[p1]) {
            ans++;
            p1++;
        }
    }
    printf("%d\n", ans);
    return 0;
}