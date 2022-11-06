#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2E5;
int a[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    map<int, int> lastOcc;
    //lastOcc.reserve(MAXN);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lastOcc[a[i]] = i;
    }
    int comps = 0;
    int ptr = 1;
    while (ptr <= n)
    {
        comps++;
        int right = lastOcc[a[ptr]];
        while (right > ptr)
        {
            ptr++;
            right = max(right, lastOcc[a[ptr]]);
        }
        ptr++;
    }
    int ans = 1;
    for (int i = 0; i < comps - 1; i++)
    {
        ans *= 2;
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << endl;
    return 0;
}