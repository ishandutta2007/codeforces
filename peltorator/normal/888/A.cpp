#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 300001;

int a[N];

int main()
{
  //  freopen("in.txt", "r", stdin);
 //   cout.precision(100);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i + 1 < n; i++)
        if ((a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0)
            ans++;
    cout << ans;
    return 0;
}