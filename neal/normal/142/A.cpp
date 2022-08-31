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

const long long LL_INF = 1LL << 60;

long long N;
vector<long long> factors;

int main()
{
    cin >> N;

    for (long long i = 1; i * i <= N; i++)
        if (N % i == 0)
        {
            factors.push_back(i);

            if (i * i < N)
                factors.push_back(N / i);
        }

    sort(factors.begin(), factors.end());
    long long minimum = LL_INF, maximum = -LL_INF;

    for (int i = 0; i < (int) factors.size(); i++)
        for (int j = 0; j < (int) factors.size() && factors[i] * factors[j] <= N; j++)
        {
            long long product = factors[i] * factors[j];

            if (N % product == 0)
            {
                long long k = N / product;
                long long stolen = (factors[i] + 1) * (factors[j] + 2) * (k + 2) - factors[i] * factors[j] * k;
                minimum = min(minimum, stolen);
                maximum = max(maximum, stolen);
            }
        }

    cout << minimum << ' ' << maximum << '\n';
    return 0;
}