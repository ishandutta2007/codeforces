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
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

typedef long long ll;

const int N = 200001;

int a[N];
int go[N];
int len[N];
int bl[N];

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] += i;
    int T = 350;//max(1, (int)sqrt(n) / 2);
    bl[0] = 0;
    for (int i = 1; i < n; i++)
    {
        bl[i] = bl[i - 1];
        if (i % T == 0)
            bl[i]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        go[i] = -1;
        if (a[i] < n)
        {
            if (bl[a[i]] == bl[i])
                go[i] = go[a[i]], len[i] = len[a[i]] + 1;
            else
                go[i] = a[i], len[i] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int type, v;
        cin >> type >> v;
        v--;
        if (type == 0)
        {
            int b;
            cin >> b;
            a[v] = v + b;
            for (int i = v; i >= 0 && bl[i] == bl[v]; i--)
            {
                go[i] = -1;
                if (a[i] < n)
                {
                    if (bl[a[i]] == bl[i])
                        go[i] = go[a[i]], len[i] = len[a[i]] + 1;
                    else
                        go[i] = a[i], len[i] = 1;
                }
            }
        }
        else
        {
            int ans = 0;
            while (a[v] < n)
            {
                if (go[v] == -1)
                {
                    ans++;
                    v = a[v];
                }
                else
                {
                    ans += len[v];
                    v = go[v];
                }
            }
            cout << v + 1 << " " << ans + 1 << "\n";
        }
    }
    return 0;
}