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

#define deb(a) cerr << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 300001;

vector<pair<int, pair<int, int> > > q;

ll pref[N];
ll a[N];

int main()
{
 //   freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    int best = 0;
    for (int i = 1; i < k; i++)
        if (n % a[i] < n % a[best])
            best = i;
    cout << best + 1 << " " << n / a[best];
    return 0;
}