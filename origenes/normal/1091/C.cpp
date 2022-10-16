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

int n, upp;

inline ll cal(ll n, int i) {
    return (1 + (n - 1) / i * i + 1) * ((n - 1) / i + 1) / 2;
}

int main() {
    scanf("%d", &n);
    upp = sqrt(n) + 0.5;
    set<ll> ans;
    FOR(i, 1, upp) if (n % i == 0) {
            ans.insert(cal(n, i));
            ans.insert(cal(n, n / i));
        }
    for (ll it : ans) printf("%lld ", it);
}