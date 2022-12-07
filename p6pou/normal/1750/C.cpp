#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int T, N;
char a[MAX_N], b[MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        a[0] = b[0] = a[N + 1] = b[N + 1] = 0;
        int c = 0;
        for (int i = 1; i <= N; i ++) {
            c += a[i] != b[i];
        }
        if (c == 0 || c == N) {
            printf("YES\n");
            vector<pair<int,int>> op;
            c = 0;
            for (int i = 1, l = 0; i <= N; i ++) {
                if (a[i] == '1' && a[i - 1] != '1') {
                    l = i;
                }
                if (a[i] == '1' && a[i + 1] != '1') {
                    op.push_back(make_pair(l, i));
                    c ^= l > 1;
                }
            }
            if ((b[1] ^ c) != '0') {
                op.push_back(make_pair(1, N));
                op.push_back(make_pair(1, 1));
                op.push_back(make_pair(2, N));
            }
            printf("%d\n", (int)op.size());
            for (auto t: op) {
                printf("%d %d\n", t.first, t.second);
            }
        } else {
            printf("NO\n");
        }
    }
    return 0;
}