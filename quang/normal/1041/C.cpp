#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m, d;
map<int, int> id;
set<int> s;
int ans[N];

int main() {
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d", &u);
        id[u] = i;
        s.insert(u);
    }
    int res = 0;
    while (!s.empty()) {
        res++;
        int u = *s.begin();
        s.erase(s.begin());
        ans[id[u]] = res;
        while (1) {
            u += d;
            auto it = s.upper_bound(u);
            if (it == s.end()) {
                break;
            }
            u = *it;
            s.erase(it);
            ans[id[u]] = res;
        }
    }
    printf("%d\n", res);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}