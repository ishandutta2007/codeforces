#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 705;

int N, M, deg [MAXN], between [MAXN][MAXN];
bool edge [MAXN][MAXN];
long long total = 0;

int main ()
{
    cin >> N >> M;

    for (int i = 0, a, b; i < M; i++)
    {
        cin >> a >> b; a--; b--;
        edge [a][b] = edge [b][a] = true;
        deg [a]++; deg [b]++;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (i != j && j != k && k != i && edge [i][k] && edge [k][j])
                    between [i][j]++;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (i != j && j != k && k != i && edge [j][k])
                {
                    int left = between [i][j], right = between [i][k];

                    if (edge [i][k])
                        left--;

                    if (edge [i][j])
                        right--;

                    total += left * right;
                }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (i != j && j != k && k != i && edge [i][j] && edge [j][k] && edge [k][i])
                    total -= deg [i] - 2;
/*
    long long slow = 0;

    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++)
            for (int c = 0; c < N; c++)
                for (int d = 0; d < N; d++)
                    for (int e = 0; e < N; e++)
                        if (a != b && a != c && a != d && a != e && b != c && b != d && b != e && c != d && c != e && d != e)
                            if (edge [a][b] && edge [b][c] && edge [c][d] && edge [d][e] && edge [e][a])
                                slow++;

    cout << slow << ' ' << total << '\n';
*/
    cout << total / 10 << '\n';
    return 0;
}