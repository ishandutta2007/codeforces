#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

ll a[maxn], k, m;
int n;

int main() {
    scanf("%d%lld%lld", &n, &m, &k);
    REP(i, n) scanf("%lld", a + i);
    sort(a, a + n, greater<ll>());
    printf("%lld", m / (k + 1) * (k * a[0] + a[1]) + m % (k + 1) * a[0]);
}