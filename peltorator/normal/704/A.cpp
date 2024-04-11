#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

vector<int> a, f, c;
vector< vector<int> > b;

int main()
{
   // fastRead;
    int n, q;
    cin >> n >> q;
    b.resize(n + 1);
    f.resize(n + 1, 0);
    int ans = 0, act = 0;
    for (int i = 0; i < q; i++)
    {
        int type, x;
        scanf("%d%d", &type, &x);
        if (type == 1)
        {
            a.push_back(x);
            b[x].push_back(a.size() - 1);
            ans++;
            c.push_back(ans);
        }
        if (type == 2)
        {
            ans -= b[x].size() - f[x];
            f[x] = b[x].size();
            c.push_back(ans);
        }
        if (type == 3)
        {
            if (x > a.size())
                x = a.size();
            for (int j = act; j < x; j++)
                if (f[a[j]] < b[a[j]].size() && b[a[j]][f[a[j]]] <= j)
                {
                    ans--;
                    f[a[j]]++;
                }
            act = max(x, act);
            c.push_back(ans);
        }
    }
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    return 0;
}