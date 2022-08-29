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

int n;
string handle, leader = "";
int succ, unsucc, a, b, c, d, e;
int leader_points;

int main ()
{
    cin >> n;

    while (n-- > 0)
    {
        cin >> handle >> succ >> unsucc >> a >> b >> c >> d >> e;
        int points = 100 * succ - 50 * unsucc + a + b + c + d + e;

        if (leader == "" || points > leader_points)
        {
            leader = handle;
            leader_points = points;
        }
    }

    cout << leader << '\n';
    return 0;
}