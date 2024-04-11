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
const int N = 500001;


int a[N];
ll pref[N];

ll check(ll a, ll b, ll c, ll d)
{
    return a * d > b * c;
}

int main()
{
 //   freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(0);
    int q;
   // cin >> q;
    cout.precision(30);
    scanf("%d", &q);
    int n = 0;
    for (int i = 0; i < q; i++)
    {
        int type;
       // cin >> type;
        scanf("%d", &type);
        if (type == 1)
        {
            int x;
            //cin >> x;
            scanf("%d", &x);
            n++;
            a[n - 1] = x;
            pref[n - 1] = x;
            if (n > 1)
                pref[n - 1] += pref[n - 2];
        }
        else
        {
            ll ch = a[n - 1];
            ll znam = 1;
            int l = 0, r = n - 1;
            while (r - l > 1)
            {
                int mid = (r + l) / 2;
                ll sum = pref[mid] + a[n - 1];
                if (check(a[mid], 1, sum, mid + 2))
                    r = mid;
                else
                    l = mid;
            }
            if (!check(pref[l] + a[n - 1], l + 2, ch, znam))
                ch = pref[l] + a[n - 1], znam = l + 2;
            cout << (ld)a[n - 1] - (ld)ch / (ld)znam << "\n";
        }
    }
    return 0;
}