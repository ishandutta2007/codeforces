#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    long long z = 0;
    cout << max(z, a[2] - a[0] - 1) + max(z, a[2] - a[1] - 1);
    return 0;
}