// #define NDEBUG
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 21, MAXS = 1000;

int N, M;
int S = 1, seen [MAXS];
char grid [MAXN][MAXN];
int dp [2 * MAXN][2 * MAXN][2 * MAXN][2 * MAXN][2];

bool valid (int r, int c, int low_sum, int high_sum, int low_diff, int high_diff, int parity)
{
    int sum = r + c, diff = r - c;
    return low_sum <= sum && sum <= high_sum && low_diff <= diff && diff <= high_diff && (sum + parity) % 2 == 0;
}

int sprague_grundy (int low_sum, int high_sum, int low_diff, int high_diff, int parity)
{
    if (low_sum > high_sum || low_diff > high_diff)
        return 0;

    int &answer = dp [low_sum][high_sum][low_diff + MAXN][high_diff + MAXN][parity];

    if (answer != -1)
        return answer;

    vector <int> values;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (valid (r, c, low_sum, high_sum, low_diff, high_diff, parity))
            {
                int sum = r + c, diff = r - c;

                if (grid [r][c] == 'L')
                {
                    values.push_back (sprague_grundy (low_sum, sum - 1, low_diff, high_diff, parity) ^
                                      sprague_grundy (sum + 1, high_sum, low_diff, high_diff, parity));
                }
                else if (grid [r][c] == 'R')
                {
                    values.push_back (sprague_grundy (low_sum, high_sum, low_diff, diff - 1, parity) ^
                                      sprague_grundy (low_sum, high_sum, diff + 1, high_diff, parity));
                }
                else if (grid [r][c] == 'X')
                {
                    values.push_back (sprague_grundy (low_sum, sum - 1, low_diff, diff - 1, parity) ^ 
                                      sprague_grundy (sum + 1, high_sum, low_diff, diff - 1, parity) ^
                                      sprague_grundy (low_sum, sum - 1, diff + 1, high_diff, parity) ^
                                      sprague_grundy (sum + 1, high_sum, diff + 1, high_diff, parity));
                }
                else
                    assert (false);
            }

    S++;

    for (int i = 0; i < (int) values.size (); i++)
        seen [values [i]] = S;

    for (int i = 0; i < MAXS; i++)
        if (seen [i] != S)
            return answer = i;

    assert (false);
    return -1;
}

int main ()
{
    scanf ("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf ("%s", grid [i]);

    memset (dp, -1, sizeof (dp));
    puts (sprague_grundy (0, N + M - 2, -(M - 1), N - 1, 0) ^ sprague_grundy (0, N + M - 2, -(M - 1), N - 1, 1) ? "WIN" : "LOSE");
    return 0;
}