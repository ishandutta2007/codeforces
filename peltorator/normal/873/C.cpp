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

const int N = 1001;

int a[N][N], b[N];

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0, del = 0;
    for (int j = 0; j < m; j++)
    {
        b[0] = a[0][j];
        for (int i = 1; i < n; i++)
            b[i] = b[i - 1] + a[i][j];
        int cur = 0, pos = -1; 
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (!a[i][j])
                continue;
            int e = b[min(n - 1, i + k - 1)] - b[i] + a[i][j];
            if (e > cur)
            {
                cur = e;
                pos = t;
            }
            t++;
        }
        if (cur)
            ans += cur, del += pos;
    }
    cout << ans << " " << del;
    return 0;
}