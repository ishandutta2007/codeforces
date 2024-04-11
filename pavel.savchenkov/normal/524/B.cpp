#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <memory.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef vector<int> Vint;

const int inf = (int)2e9;
int work(const Vint &w, const Vint &h)
{
    int ans = inf;

    int n = (int)w.size();
    assert(w.size() == h.size());

    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int j = 0; j < n; j++)
            ok &= (w[j] <= h[i] || h[j] <= h[i]);
        if (!ok)
            continue;

        int width = 0;
        for (int j = 0; j < n; j++)
        {
            if (w[j] <= h[i] && h[j] <= h[i])
                width += min(w[j], h[j]);
            else if (w[j] <= h[i])
                width += h[j];
            else if (h[j] <= h[i])
                width += w[j];
            else
                assert(0);
        }

        ans = min(ans, width * h[i]);
    }

    assert(ans != inf);
    return ans;
}

void solve(int n)
{
    Vint w(n), h(n);
    for (int i = 0; i < n; i++)
        scanf(" %d %d", &w[i], &h[i]);

    int ans = inf;
    int cur = work(w, h);
    ans = min(ans, cur);
    cur = work(h, w);
    ans = min(ans, cur);

    printf("%d\n", ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    while (cin >> n)
        solve(n);
}