#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int deg[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++;
        deg[v]++;
    }
    int mx = 0;
    vector<int> one, two;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, deg[i]);
        if (deg[i] == 1) {
            one.push_back(i);
        } else if (deg[i] > 2) {
            two.push_back(i);
        }
    }
    if (mx <= 2) {
        printf("Yes\n1\n%d %d\n", one[0], one[1]);
    } else {
        if (two.size() > 1) {
            printf("No\n");
        } else {
            printf("Yes\n");
            printf("%d\n", (int)one.size());
            for (int u : one) {
                printf("%d %d\n", u, two[0]);
            }
        }
    }
    return 0;
}