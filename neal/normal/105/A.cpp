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

inline long long int_in ()
{
    long long x;

#ifdef LOCAL
    scanf ("%lld", &x);
#else
    scanf ("%I64d", &x);
#endif

    return x;
}

inline void int_out (long long x, char end = '\n')
{
#ifdef LOCAL
    printf ("%lld%c", x, end);
#else
    printf ("%I64d%c", x, end);
#endif
}

// End of prewritten code.

const double EPS = 1e-10;

int N, M;
double K;
map <string, int> skills;

int main ()
{
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        string name;
        int exp;
        cin >> name >> exp;

        int nexp = (int) (K * exp + EPS);

        if (nexp >= 100)
            skills [name] = nexp;
    }

    for (int i = 0; i < M; i++)
    {
        string name;
        cin >> name;

        if (skills.count (name) == 0)
            skills [name] = 0;
    }

    cout << skills.size () << '\n';

    for (map <string, int> :: iterator it = skills.begin (); it != skills.end (); it++)
        cout << it->first << ' ' << it->second << '\n';

    return 0;
}