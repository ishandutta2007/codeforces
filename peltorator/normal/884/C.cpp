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

const int N = 100001;

int p[N], used[N];
vector<ll> q;

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            int t = 1;
            used[i] = 1;
            int j = p[i];
            while (i != j)
            {
                used[j] = 1;
                t++;
                j = p[j];
            }
            q.push_back(t);
        }
    }
    sort(q.begin(), q.end());
    if (q.size() > 1)
    {
        q[q.size() - 2] += q.back();
        q.pop_back();
    }
    ll ans = 0;
    for (int i = 0; i < q.size(); i++)
        ans += q[i] * q[i];
    cout << ans;
    return 0;
}