#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, P, M;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    P = 1;
    M = 0;

    while (P < N)
    {
        P *= 2;
        M++;
    }

    printf("%d\n", M);

    for (int bit = 0; bit < M; bit++)
    {
        vector<int> first;

        for (int i = 0; i < N; i++)
            if (i & 1 << bit)
                first.push_back(i + 1);

        printf("%d", (int) first.size());

        for (int i = 0; i < (int) first.size(); i++)
            printf(" %d", first[i]);

        printf("\n");
    }

    return 0;
}