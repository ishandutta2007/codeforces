#include <bits/stdc++.h>

#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stdout)
typedef long long ll;

using namespace std;

const int dd = (int)2e5 + 7;

set<int> S[4];
int p[dd], a[dd], b[dd];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        S[a[i]].insert(p[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        S[b[i]].insert(p[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int c;
        scanf("%d", &c);
        if (!(int)S[c].size())
            printf("-1 ");
        else {
            int x;
            printf("%d ", x = *S[c].begin());
            S[1].erase(x);
            S[2].erase(x);
            S[3].erase(x);
        }
    }
    return 0;
}