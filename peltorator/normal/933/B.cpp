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

vector<int> q;

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    ll p, k;
    cin >> p >> k;
    int t = 0;
    while (p)
    {
        if (t == 0)
        {
            q.push_back(p % k);
            p /= k;
        }
        else
        {
            q.push_back((k - p % k) % k);
            p = (p + k - 1) / k;
        }
        t ^= 1;
    }
    cout << q.size() << endl;
    for (ll i : q)
        cout << i << " ";
    return 0;
}