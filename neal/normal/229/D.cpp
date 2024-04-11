#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int N_MAX = 5005, INF = 15000;

int N, height[N_MAX], psum[N_MAX];
short dp_ops[N_MAX][N_MAX];
// dp_ops[end][begin]

int main()
{
    scanf("%d", &N);
    psum[0] = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &height[i]);
        psum[i + 1] = psum[i] + height[i];
    }

    dp_ops[0][0] = 0;

    for (int end = 1; end <= N; end++)
    {
        dp_ops[end][end] = INF;

        for (int begin = end - 1, start = begin; begin >= 0; begin--)
        {
            while (start > 0 && psum[end] - psum[begin] >= psum[begin] - psum[start - 1])
                start--;

            assert (0 <= start && start <= begin && begin < end && end <= N);
            dp_ops[end][begin] = min(dp_ops[begin][start] + (end - begin - 1), (int) dp_ops[end][begin + 1]);
        }
    }

    int best = INF;

    for (int i = 0; i < N; i++)
        best = min(best, (int) dp_ops[N][i]);

    printf("%d\n", best);
    return 0;
}