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

const ll MOD = 998244353;
const int maxn = 212345;

char s[maxn];
int n;

int main() {
    scanf("%d%s", &n, s + 1);
    int l = 1, r = 1;
    while (s[l + 1] == s[1]) l++;
    while (s[n - r] == s[n]) r++;
    if (s[1] == s[n]) printf("%lld", ll(l + 1) * (r + 1) % MOD);
    else printf("%d", l + r + 1);
}