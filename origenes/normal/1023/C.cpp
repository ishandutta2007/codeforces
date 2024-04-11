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
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

stack<int> s;
char str[maxn];
bool vis[maxn];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    REP(i, n) {
        if (str[i] == '(') s.push(i);
        else {
            vis[s.top()] = vis[i] = true;
            s.pop();
            k -= 2;
            if (!k) break;
        }
    }
    REP(i, n) if (vis[i]) putchar(str[i]);
    puts("");
    return 0;
}