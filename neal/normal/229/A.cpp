#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N_MAX = 105, M_MAX = 10005, INF = 5000000;

int N, M;
char table[N_MAX][M_MAX];
int near_one[N_MAX][M_MAX];

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%s", table[i]);

    for (int i = 0; i < N; i++)
    {
        int left = INF;

        for (int j = 0; j < M; j++)
            if (table[i][j] == '1')
                left = j - M;

        for (int j = 0; j < M; j++)
        {
            if (table[i][j] == '1')
                left = j;

            near_one[i][j] = left == INF ? INF : j - left;
        }

        int right = INF;

        for (int j = M - 1; j >= 0; j--)
            if (table[i][j] == '1')
                right = j + M;

        for (int j = M - 1; j >= 0; j--)
        {
            if (table[i][j] == '1')
                right = j;

            near_one[i][j] = min(near_one[i][j], right == INF ? INF : right - j);
        }
    }

    int best = INF;

    for (int j = 0; j < M; j++)
    {
        int sum = 0;

        for (int i = 0; i < N; i++)
            sum += near_one[i][j];

        best = min(best, sum);
    }

    printf("%d\n", best < INF ? best : -1);
    return 0;
}