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

const int N_MAX = 200005;

struct compare_complex
{
    bool operator() (complex<int> a, complex<int> b)
    {
        if (a.real() != b.real())
            return a.real() < b.real();
        else
            return a.imag() < b.imag();
    }
};

int N, K;
complex<int> crystal[N_MAX];
set<complex<int>, compare_complex> crystals, candidates;
vector<complex<int> > solutions;

bool test(complex<int> mid)
{
    int mismatch = 0;

    for (int i = 0; i < N && mismatch <= K; i++)
    {
        complex<int> p = 2 * mid - crystal[i];

        if (crystals.find(p) == crystals.end())
            mismatch++;
    }

    return mismatch <= K;
}

int main ()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &crystal[i].real(), &crystal[i].imag());
        crystal[i] *= 2;
        crystals.insert(crystal[i]);
    }

    if (N <= K)
    {
        puts("-1");
        return 0;
    }

    sort(crystal, crystal + N, compare_complex());

    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++)
        {
            complex<int> mid = (crystal[i] + crystal[N - 1 - j]) / 2;

            if (candidates.insert(mid).second && test(mid))
                solutions.push_back(mid);
        }

    printf("%d\n", (int) solutions.size());

    for (int i = 0; i < (int) solutions.size(); i++)
        printf("%.1lf %.1lf\n", solutions[i].real() / 2.0, solutions[i].imag() / 2.0);

    return 0;
}