#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1000000010;

int n, m;
int a[N], b[N];
map<int, int> s;
map<pair<int, int>, int> ma;

int main() {
    int foo;
    int res = 0;
    scanf("%d %d", &n, &foo);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        s[a[i]]++;
        int cur = 1;
        while (cur < INF) {
            cur <<= 1;
            int foo = a[i] % cur;
            ma[make_pair(cur, foo)]++;
        }
    }
    scanf("%d %d", &m, &foo);
    for (int i = 1; i <= m; i++) {
        scanf("%d", b + i);
        s[b[i]]++;
        int cur = 1;
        while (cur < INF) {
            cur <<= 1;
            int foo = (b[i] % cur + cur / 2) % cur;
            ma[make_pair(cur, foo)]++;
        }
    }
    for (auto u : s) {
        res = max(res, u.second);
    }
    for (auto u : ma) {
        res = max(res, u.second);
    }
    cout << res << endl;
    return 0;
}