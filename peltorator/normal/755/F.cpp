#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;

vector<int> a, used, t;
bitset<1000001> dp;
vector<int> q;

int main()
{
    int n, k;
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    used.assign(n + 1, 0);
    q.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            int num = 1;
            used[i] = 1;
            int j = a[i];
            while (j != i)
            {
                used[j] = 1;
                j = a[j];
                num++;
            }
            q[num]++;
            t.push_back(num);
        }
    }
    dp.set(n);
    for (int i = 1; i <= n; i++)
        if (q[i] > 0)
        {
            int kk = 1;
            while (q[i] > 0)
            {
              kk = min(kk, q[i]);
              int x = i * kk;
              dp |= (dp >> x);
              q[i] -= kk;
              kk *= 2;
            }
        }
    if (dp.test(n - k))
        cout << k;
    else
        cout << k + 1;
    cout << " ";
    int ans = 0;
    for (int i = 0; i < t.size() && k > 0; i++)
    {
        ans += 2 * min(t[i] / 2, k);
        k -= min(t[i] / 2, k);
    }
    for (int i = 0; i < t.size(); i++)
        if (t[i] % 2 == 1 && k > 0)
            ans++, k--;
    cout << ans;
    return 0;
}