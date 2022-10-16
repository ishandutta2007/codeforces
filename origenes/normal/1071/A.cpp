#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

int a, b;

int main() {
    scanf("%d%d", &a, &b);
    int now = 0, n = 0, num = 1, m = 0;
    FOR(i, 1, a + 5) {
        if (now + i > a) {
            n = i - 1;
            int diff = a - now;
            num = i - diff;
            break;
        }
        now += i;
    }
    printf("%d\n", n);
    FOR(i, 1, n) if (i != num) printf("%d ", i);
    if (n + 1 != num) printf("%d\n", n + 1);
    else puts("");
    if (num > b) {
        printf("0\n\n");
        return 0;
    }
    vector<int> ans;
    m = 1, b -= num;
    ans.pb(num);
    FOR(i, n + 2, b + 5) if (b >= i) {
            b -= i;
            m++;
            ans.pb(i);
        }
    printf("%d\n", m);
    for (auto it : ans) printf("%d ", it);
    puts("");
    return 0;
}