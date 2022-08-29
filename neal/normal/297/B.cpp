#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100005;

int N, M, K;
int alice[MAX], bob[MAX];

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", &alice[i]);

    for (int j = 0; j < M; j++)
        scanf("%d", &bob[j]);

    sort(alice, alice + N);
    sort(bob, bob + M);

    for (int a = N - 1, b = M; a >= 0; a--)
    {
        while (b > 0 && bob[b - 1] >= alice[a])
            b--;

        if (N - a > M - b)
        {
            puts("YES");
            return 0;
        }
    }
    
    puts("NO");
    return 0;
}