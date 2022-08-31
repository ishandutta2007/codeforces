#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 1000005;

int N, M, deg[MAX];

int main()
{
    scanf("%d %d", &N, &M);
    long long total = (long long) N * (N - 1) * (N - 2) / 6;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        total += deg[a] + deg[b] - (N - 2);
        deg[a]++;
        deg[b]++;
    }

    cout << total << '\n';
    return 0;
}