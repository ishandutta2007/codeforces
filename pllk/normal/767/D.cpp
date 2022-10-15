#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, k;
int f[1222333];
pair<int,int> s[1222333];

bool ok(int x) {
    int i1 = 0, i2 = m-x;
    for (int u = 0; ; u++) {
        for (int g = 0; g < k; g++) {
            if (i1 < n && i2 < m) {
                if (f[i1] < s[i2].first) i1++;
                else i2++;
            } else if (i1 < n) {
                i1++;
            } else if (i2 < m) {
                i2++;
            } else return true;
        }
        if (i1 < n && f[i1] == u) return false;
        if (i2 < m && s[i2].first == u) return false;
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%d", &f[i]);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        s[i].first = x;
        s[i].second = i+1;
    }
    sort(f,f+n);
    sort(s,s+m);
    int u = -1;
    for (int b = m; b >= 1; b /= 2) {
        while (u+b <= m && ok(u+b)) u += b;
    }
    printf("%d\n", u);
    if (u != -1) {
        for (int i = 0; i < u; i++) {
            printf("%d ", s[m-i-1].second);
        }
        printf("\n");
    }
}