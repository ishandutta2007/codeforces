#include <bits/stdc++.h>
using namespace std;

int N, L, D, arr[500005], blim[500005], flim[500005], dp[500005], l[500005], r[500005];
multiset<int> M;
vector<int> through;

int main() {
    scanf("%d%d%d", &N, &D, &L);
    if (L > N) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    memset(flim, -1, sizeof(flim));
    int b = 0, e = -1;
    for (int i = 0; i < N; i++) {
        if (e != N) {
            while (M.size() == 0 || *M.rbegin() - *M.begin() <= D) {
                e++;
                if (e == N) break;
                M.insert(arr[e]);
            }
        }
        blim[i] = e;
        M.erase(M.find(arr[i]));
    }
    for (int i = 0; i < N; i++) flim[i] = upper_bound(blim, blim + N, i) - blim;
    for (int i = 0; i < N; i++) {
        r[i] = max(-1, i - L);
        l[i] = min(N - 1, flim[i] - 1);
    }
    for (int i = 0; i < N; i++) {
        if (l[i] > r[i]) dp[i] = 1000000000;
        else through.push_back(i);
    }
    M.clear();
    M.insert(0);
    b = -1;
    e = -1;
    for (int i = 0; i < through.size(); i++) {
        for (; e < r[through[i]];) {
            e++;
            M.insert(dp[e]);
        }
        for (; b < l[through[i]]; b++) {
            if (b == -1) {
                M.erase(M.find(0));
                continue;
            }
            M.erase(M.find(dp[b]));
        }
        dp[through[i]] = *M.begin() + 1;
    }
    if (dp[N-1] >= 1000000000) printf("-1\n");
    else printf("%d\n", dp[N-1]);
}