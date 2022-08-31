#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N_MAX = 205, AB_MAX = 40005, INF = 1010000000;

int N, A, B, H[N_MAX], psum[N_MAX];
int dp[N_MAX][AB_MAX][2];

int solve(int fence, int a_sum, int current)
{
    int &sol = dp[fence][a_sum][current];

    if (sol != -1)
        return sol;

    int b_sum = psum[fence] - a_sum;

    if (a_sum > A || b_sum > B)
        return INF;

    if (fence == N)
        return 0;

    int contact = fence == 0 ? 0 : min(H[fence], H[fence - 1]);
    return sol = min((current == 1 ? contact : 0) + solve(fence + 1, a_sum + H[fence], 0),
                     (current == 0 ? contact : 0) + solve(fence + 1, a_sum, 1));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &N, &A, &B);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &H[i]);
        psum[i + 1] = psum[i] + H[i];
    }

    memset(dp, -1, sizeof(dp));
    int answer = max(solve(0, 0, 0), solve(0, 0, 1));
    printf("%d\n", answer < INF ? answer : -1);
    return 0;
}