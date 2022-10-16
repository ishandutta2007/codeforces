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

const int maxn = 112345;

int c[maxn], t[maxn], n;
vector<int> lis[2];

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", c + i);
    FOR(i, 1, n) scanf("%d", t + i);
    if (c[1] != t[1] || c[n] != t[n]) {
        puts("No");
        return 0;
    }
    FOR(i, 2, n) lis[0].eb(c[i] - c[i - 1]);
    FOR(i, 2, n) lis[1].eb(t[i] - t[i - 1]);
    sort(all(lis[0]));
    sort(all(lis[1]));
    puts(lis[0] == lis[1] ? "Yes" : "No");
}