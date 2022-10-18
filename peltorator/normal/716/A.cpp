#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    int ans = 0, cur = -1e9;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k - cur > c)
            ans = 1;
        else
            ans++;
        cur = k;
    }
    cout << ans;
    return 0;
}