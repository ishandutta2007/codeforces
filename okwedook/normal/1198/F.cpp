#include <stdio.h>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void read(int &a) {
    a = 0;
    static char c;
    while (c = getchar(), c >= '0')
        a = (a << 3) + (a << 1) + (c - '0');
}
 
signed main() {
    srand(32895);
    int n;
    read(n);
    vector<int> a(n), ind(n), ans(n, 2);
    for (auto &i : a) read(i);
    for (int i = 0; i < n; ++i) ind[i] = i;
    while (clock() < 100) {
        int g = 0;
        for (auto i : ind) {
            int past = g;
            g = __gcd(g, a[i]);
            if (g != past) ans[i] = 1;
        }
        if (g == 1) {
            int v = 0;
            for (int i = 0; i < n; ++i)
                if (ans[i] == 2)
                    v = __gcd(v, a[i]);
            if (v == 1) {
                printf("YES\n");
                for (auto i : ans) printf("%d ", i);
                return 0;
            }
        }
        for (int i = 0; i < n; ++i) ans[i] = 2;
        random_shuffle(ind.begin(), ind.end());
    }
    printf("NO");
    return 0;
}