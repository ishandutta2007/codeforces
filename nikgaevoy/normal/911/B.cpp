#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>

#include <cassert>
#include <cmath>

using namespace std;

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, a, b;

    cin >> n >> a >> b;

    int ans = 0;

    for (int i = 1; i < n; i++)
        ans = max (ans, min (a / i, b / (n - i)));

    cout << ans << endl;
}

int main ()
{
    solve ();

    return 0;
}