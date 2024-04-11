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
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += max(0, k - a[i + 1] - a[i]);
        a[i + 1] += max(0, k - a[i + 1] - a[i]);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}