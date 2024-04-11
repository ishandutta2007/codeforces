#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 200001;

ll a[MAXN];

vector<pair<ll, ll> > lines, arr;

ld f(ld k1, ld b1, ld k2, ld b2)
{
    return (b1 - b2) / (k2 - k1);
}

void addLine(ll k, ll b)
{
    while (lines.size() > 1)
    {
        ld cur = f(k, b, lines.back().first, lines.back().second);
        ld last = f(lines.back().first, lines.back().second, lines[lines.size() - 2].first, lines[lines.size() - 2].second);
        if (lines.back().first == k || cur < last)
            lines.pop_back();
        else
            break;
    }
    lines.push_back({k, b});
}

ll findmin(ll x)
{
    int l = 0, r = lines.size();
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (f(lines[mid].first, lines[mid].second, lines[mid - 1].first, lines[mid - 1].second) > (ld)x)
            r = mid;
        else
            l = mid;
    }
    return lines[l].first * x + lines[l].second;
}

ll f(int l, int r)
{
    if (r < l)
        return 0;
    if (l == r)
        return max(a[l], 0LL);
    int mid = (r + l) / 2;
    ll ans = max(f(l, mid), f(mid + 1, r));
    arr.clear();
    ll curans = 0, sum = 0;
    for (int i = mid + 1, j = 1; i <= r; i++, j++)
    {
        curans += (ll)j * a[i];
        sum += a[i];
        arr.push_back({-sum, -curans}); 
    }
    sort(arr.rbegin(), arr.rend());
    lines.clear();
    for (int i = 0; i < arr.size(); i++)
        addLine(arr[i].first, arr[i].second);
    curans = 0;
    sum = 0;
    ll now = 0;
    for (int i = mid, j = 1; i >= l; i--, j++)
    {
        sum += a[i];
        curans += sum;
        now = max(now, curans - findmin(j));
    }
   // cout << l + 1 << " " << r + 1 << " " << now << endl;
    return max(ans, now);
}

int main()
{
 //   freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << f(0, n - 1);
    return 0;
}