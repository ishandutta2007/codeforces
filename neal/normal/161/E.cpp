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

const int MAX = 100000, DIGITS = 5;

int T, N;
char str[DIGITS + 1];
bool prime[MAX];
vector<int> prefixes[DIGITS + 1][DIGITS + 1][MAX]; // [digits][prefix length][prefix]
int power10[DIGITS + 1];

int n_digits(int x)
{
    int digits = 0;

    do
    {
        x /= 10;
        digits++;
    }
    while (x > 0);

    return digits;
}

bool is_prefix(int len, int prefix)
{
    return !prefixes[N][len][prefix].empty();
}

void sieve()
{
    power10[0] = 1;

    for (int i = 1; i <= DIGITS; i++)
        power10[i] = power10[i - 1] * 10;

    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i < MAX; i++)
        if (prime[i])
            for (int j = 2 * i; j < MAX; j += i)
                prime[j] = false;

    for (int i = 2; i < MAX; i++)
        if (prime[i])
        {
            int digits = n_digits(i);

            while (digits <= DIGITS)
            {
                for (int j = 0; j <= digits; j++)
                    prefixes[digits][j][i / power10[digits - j]].push_back(i);

                digits++;
            }
        }
}

map<int, int> dp;

int solve(int row, int columns[DIGITS])
{
    if (row == N)
        return 1;

    int state = 10 * N + row;

    for (int j = row; j < N; j++)
        state = power10[row] * state + columns[j];

    if (dp.find(state) != dp.end())
        return dp[state];

    int total = 0;
    vector<int> &v = prefixes[N][row][columns[row]];

    for (int i = 0; i < (int) v.size(); i++)
    {
        int completion = v[i];

        for (int j = row; j < N; j++)
            columns[j] = columns[j] * 10 + (completion / power10[N - 1 - j]) % 10;

        bool possible = true;

        for (int j = row + 1; j < N; j++)
            if (!is_prefix(row + 1, columns[j]))
                possible = false;

        if (possible)
            total += solve(row + 1, columns);

        for (int j = row; j < N; j++)
            columns[j] /= 10;
    }

    return dp[state] = total;
}

int main()
{
    sieve();
    scanf("%d", &T);

    while (T-- > 0)
    {
        scanf("%s", str);
        N = strlen(str);
        int columns[DIGITS];

        for (int i = 0; i < N; i++)
            columns[i] = str[i] - '0';

        printf("%d\n", solve(1, columns));
    }

    return 0;
}