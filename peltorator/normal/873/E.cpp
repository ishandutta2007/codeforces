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

const int N = 4001, LOG = 23;

vector<pair<int, int> > b;
int a[N];
int c[N];
int ans[N];
int bin[N][LOG];
int logs[N];

int find(int l, int r)
{
    int t = logs[r - l + 1];
    return max(bin[l][t], bin[r - (1 << t) + 1][t]);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == (2 << t))
            t++;
        logs[i] = t;
    }
    int n;
    cin >> n;
    b.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; i++)
        a[i] = b[i].first, c[i] = b[i].second;
    a[n] = 0;
    for (int i = 0; i < n; i++)
        bin[i][0] = a[i] - a[i + 1];
    for (int j = 1; j < LOG; j++)
        for (int i = 0; i < n; i++)
        {
            bin[i][j] = bin[i][j - 1];
            if (i + (1 << (j - 1)) < n)
                bin[i][j] = max(bin[i][j - 1], bin[i + (1 << (j - 1))][j - 1]);
        }
    int b1 = -1, b2 = -1, b3 = -1, xx = -1, yy = -1, zz = -1;
    for (int x = 0; x < n; x++)
        for (int y = x + 1; y < n - 1; y++)
        {
            if (2 * (x + 1) < y - x || 2 * (y - x) < x + 1)
                continue;
            int l = (max(x + 1, y - x) + 1) / 2 + y;
            int r = 2 * (min(x + 1, y - x)) + y;
            l = max(l, y + 1);
            r = min(r, n - 1);
           // cout << x << " " << y << " " << l << " " << r << endl;
            if (l > r)
                continue;
            int kek = a[x] - a[x + 1];
            int mem = a[y] - a[y + 1];
            int tau = find(l, r);
            //cout << kek << " " << mem << " " << tau << endl;
            if (b1 < kek || (b1 == kek && (b2 < mem || (b2 == mem && b3 < tau))))
            {
                b1 = kek;
                b2 = mem;
                b3 = tau;
                xx = x;
                yy = y;
            }
        }
    //cout << xx << " " << yy << endl;
   // cout << b1 << " " << b2 << " " << b3 << endl;
    int x = xx;
    int y = yy;
    int z = yy + 1;
    int l = (max(x + 1, y - x) + 1) / 2 + y;
    l = max(l, y + 1);
    z = l;
    //cout << b3 << endl;
    while (a[z] - a[z + 1] != b3)
        z++;
    //cout << x << " " << y << " " << z << endl;
    for (int i = 0; i <= x; i++)
        ans[c[i]] = 1;
    for (int i = x + 1; i <= y; i++)
        ans[c[i]] = 2;
    for (int i = y + 1; i <= z; i++)
        ans[c[i]] = 3;
    for (int i = z + 1; i < n; i++)
        ans[c[i]] = -1;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}