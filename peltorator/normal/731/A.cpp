#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

int main()
{
    string s = "a", t;
    cin >> t;
    s += t;
    int ans = 0;
    for (int i = 1; i < s.size(); i++)
        ans += min(abs(s[i] - s[i - 1]), 26 - abs(s[i] - s[i - 1]));
    cout << ans;
    return 0;
}