#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300000 + 5;

int N, K;
char s[MAX_N];
set<int> b[MAX_N];
int ax[MAX_N];
set<int> a[MAX_N];
int ans;

void merge_a(int x, int y, int z) {
    if (a[x].size() < a[y].size()) {
        swap(x, y);
    }
    ax[x] = z;
    for (int j: a[y]) {
        b[j].erase(y);
        if (a[x].count(j)) {
            b[j].erase(x);
            a[x].erase(j);
        } else {
            a[x].insert(j);
            b[j].insert(x);
        }
    }
}

int main() {
    scanf("%d%d", &N, &K);
    scanf("%s", s + 1);
    for (int i = 1, c; i <= K; i ++) {
        scanf("%d", &c);
        for (int j = 0, t; j < c; j ++) {
            scanf("%d", &t);
            b[t].insert(i);
            a[i].insert(t);
        }
        ax[i] = 1;
    }
    for (int i = 1; i <= N; i ++) {
        if (s[i] == '1') {
            if (b[i].size() == 1)  {
                //
                int x = *b[i].begin();
                // printf("i=%d,<1>,x=%d\n", i, x);
                for (int j: a[x]) {
                    b[j].erase(x);
                }
            } else if (b[i].size() == 2) {
                //
                int x = *b[i].begin();
                int y = *++ b[i].begin();
                // printf("i=%d,<2>,x=%d, y=%d\n", i, x, y);
                merge_a(x, y, ax[x] + ax[y]);
            }
        } else {
            if (b[i].size() == 1) {
                //
                int x = *b[i].begin();
                ans += ax[x];
                // printf("i=%d,<3>,x=%d\n", i, x);
                for (int j: a[x]) {
                    b[j].erase(x);
                    s[j] ^= 1;
                }
            } else if (b[i].size() == 2){
                //
                int x = *b[i].begin();
                int y = *++ b[i].begin();
                if (ax[x] > ax[y]) {
                    swap(x, y);
                }
                for (int j: a[x]) {
                    s[j] ^= 1;
                }
                // printf("i=%d,<4>,x=%d(%d), y=%d(%d)\n", i, x, ax[x], y, ax[y]);
                ans += ax[x];
                merge_a(x, y, ax[y] - ax[x]);
            } else {
                printf("error\n");
            }
        }
        printf("%d\n", ans);
        // printf("%s\n", s + 1);
    }
    return 0;
}