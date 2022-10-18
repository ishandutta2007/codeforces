#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <memory.h>
#include <map>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define deb(a) cerr << "Debug: " << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 10000;

int a[N];

int pref1[N], pref2[N];

int main()
{
  //  freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int two = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            pref1[i] = 1;
        else
            pref2[i] = 1;
        if (i)
            pref1[i] += pref1[i - 1], pref2[i] += pref2[i - 1];
    }
    one = pref1[n - 1];
    two = pref2[n - 1];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num1 = 0;
        int num2 = 0;
        int maxx = -1e9;
        for (int j = i; j < n; j++)
        {
            if (a[j] == 2)
                num2++;
            else
                num1++;
            int cur = 0;
            if (i)
                cur = pref1[i - 1];
            cur += two - pref2[j];
            maxx = max(maxx, 2 * num2 - (j - i + 1));
            ans = max(ans, cur + maxx + num1);
        }
        int cur = pref1[i];
        int t = num2 - pref2[i];
        ans = max(ans, t + cur);
    }
    cout << ans;
    return 0;
}