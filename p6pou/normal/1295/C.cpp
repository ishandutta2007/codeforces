#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000 + 5;

int S, T;
char s[MAX_N], t[MAX_N];
vector<int> sp[26];

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT --) {
        scanf("%s%s", s + 1, t + 1);
        S = strlen(s + 1);
        T = strlen(t + 1);
        for (int i = 1; i <= S; i ++) {
            sp[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i ++) {
            sp[i].push_back(S + 1);
        }
        int ans = 1;
        for (int i = 1, k = 1; i <= T; i ++) {
            int ti = t[i] - 'a';
            if (sp[ti].size() == 1) {
                ans = -1;
                break;
            }
            int kk = *lower_bound(sp[ti].begin(), sp[ti].end(), k);
            if (kk == S + 1) {
                ans ++;
                kk = sp[ti][0];
            }
            k = kk + 1;
        }
        printf("%d\n", ans);
        for (int i = 0; i < 26; i ++) {
            sp[i].clear();
        }
    }
    return 0;
}