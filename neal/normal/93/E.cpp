#include <algorithm>
#include <bitset>
#define NDEBUG
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

const int MAXK = 105, SAVE = 50000;

long long N;
int K, A [MAXK];
int save [MAXK][SAVE];

long long go (long long n, int num)
{
    if (n == 0)
        return 0;

    if (num == K)
        return n;

    if (n < SAVE && save [num][n] != -1)
        return save [num][n];

    long long answer = go (n, num + 1) - go (n / A [num], num + 1);

    if (n < SAVE)
        save [num][n] = answer;

    assert (answer >= 0);
    return answer;
}

int main ()
{
    cin >> N >> K;

    for (int i = 0; i < K; i++)
        cin >> A [i];

    sort (A, A + K);
    reverse (A, A + K);
    memset (save, -1, sizeof (save));
    cout << go (N, 0) << '\n';
    return 0;
}