#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    vector<int> first(N, K + 1), last(N, -1);
    for (int i = 0; i < K; ++i) {
        int x;
        scanf("%d", &x);
        x -= 1;
        first[x] = min(first[x], i);
        last[x] = max(last[x], i);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && last[i - 1] <= first[i]) ans += 1;
        if (i < N - 1 && last[i + 1] <= first[i]) ans += 1;
        if (last[i] == -1) ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}