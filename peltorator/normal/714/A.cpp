#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    long long l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    long long x = max(l1, l2), y = min(r1, r2), ans = y - x + 1;
    if (k >= x && k <= y)
        ans--;
    if (ans < 0)
        ans = 0;
    cout << ans;
    return 0;
}