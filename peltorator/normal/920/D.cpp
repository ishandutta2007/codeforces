#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;
const int N = 100001, M = 2;
ll a[N];
ll dp[N];
ll dp1[N];
pair<ll, ll> pr[N];
vector<ll> arr;
vector<ll> q;

int used[N];

int main()
{
  //  freopen("in.txt", "r", stdin);
    ll n, k;
    ll w;
    cin >> n >> k >> w;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] == w)
        {
            cout << "YES";
            return 0;
        }
    }
    if (sum < w)
    {
        cout << "NO";
        return 0;
    }
    if (w % k == 0)
    {
        cout << "YES\n";
        for (int i = 1; i < n; i++)
            if (a[i])
                cout << (a[i] + k - 1) / k << " " << i + 1 << " 1\n";
        if (w)
            cout << w / k << " 1 2";
        return 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = k - 1; j >= 0; j--)
        {
            int l = (a[i] + j) % k;
            if (dp[j] && dp[l] == 0 && dp1[l] == 0)
            {
                dp1[l] = 1;
                pr[l] = {i, j};
            }
        }
        for (int i = 0; i < k; i++)
            dp[i] |= dp1[i];
    }
    if (dp[w % k] == 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    ll h = w % k;
    while (h)
    {
        arr.push_back(pr[h].first);
        used[pr[h].first] = 1;
        h = pr[h].second;
    }
    cout << endl;
    ll sz = a[arr[0]];
    for (int i = 1; i < arr.size(); i++)
        if (a[arr[i]])
            cout << (a[arr[i]] + k - 1) / k << " " << arr[i] + 1 << " " << arr[0] + 1 << "\n", sz += a[arr[i]];
    cout << endl;
    ll best = -1;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            if (best == -1)
                best = i;
            else if (a[i])
                cout << (a[i] + k - 1) / k << " " << i + 1 << " " << best + 1 << "\n";
        }
    }
    if (best == -1)
    {
        best = 0;
        if (arr[0] == 0)
            best = 1;
    }
    if (sz < w)
        cout << (w - sz) / k << " " << best + 1 << " " << arr[0] + 1;
    else if (sz != w)
        cout << (sz - w) / k << " " << arr[0] + 1 << " " << best + 1;
    return 0;
}