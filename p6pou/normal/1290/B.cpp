#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int N, Q;
char s[MAX_N];
int cnt[MAX_N][26];

int main() {
    scanf("%s", s + 1);
    N = strlen(s + 1);
    for (int i = 1; i <= N; i ++) {
        for (int j = 0; j < 26; j ++) {
            cnt[i][j] = cnt[i - 1][j] + (s[i] == j + 'a');
        }
    }
    scanf("%d", &Q);
    while (Q --) {
        int l, r, c = 0;
        scanf("%d%d", &l, &r);
        for (int j = 0; j < 26; j ++) {
            c += (cnt[r][j] - cnt[l - 1][j] > 0);
        }
        if (c == 1) {
            printf(l == r ? "Yes\n" : "No\n");
        } else if (c == 2) {
            printf(s[l] == s[r] ? "No\n" : "Yes\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}