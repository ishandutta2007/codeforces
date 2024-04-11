#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

typedef long long ll;
typedef double ld;

bool solve();

ll time()
{
    return (ll)clock() * 1000LL / CLOCKS_PER_SEC;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t = 1;
#ifdef ONLINE_JUDGE
    t = 1;
#endif
    while (t--)
        solve();
#ifndef ONLINE_JUDGE
	cerr << "time: " << time() << " ms" << endl;
#endif
    return 0;
}

const int N = 300001;
const ll INF = 1e15;

char c[N];
ll p[N];

bool solve()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i] >> c[i];
    /*ll ans = 0;*/
    int i = 0;
    while (i < n && c[i] != 'G')
        i++;
    if (i == n)
    {
        ll ans = 0;
        i = 0;
        while (i <= n && c[i] != 'R')
            i++;
        if (i != n + 1)
        {
            int j = n;
            while (c[j] != 'R')
                j--;
            ans += p[j] - p[i];
        }
        i = 1;
        while (i <= n && c[i] != 'B')
            i++;
        if (i != n + 1)
        {
            int j = n;
            while (c[j] != 'B')
                j--;
            ans += p[j] - p[i];
        }
        cout << ans;
        return 0;
    }/*
    int j = 0;
    while (j < i && c[j] != 'B')
        j++;
    if (j < i)
        ans += p[i] - p[j];*/
    ll ans = 0;
    c[0] = 'G';
    p[0] = -INF;
    c[n + 1] = 'G';
    p[n + 1] = INF;
    n += 2;
    i = 0;
    while (i + 1 < n)
    {
        int j = i + 1;
        while (c[j] != 'G')
            j++;
        ll bestb = -1, bestr = -1;
        bool b = 0, r = 0;
        for (int k = i + 1; k < j; k++)
            if (c[k] == 'B')
                b = 1;
            else if (c[k] == 'R')
                r = 1;
        int last = i;
        for (int k = i + 1; k <= j; k++)
            if (c[k] == 'B' || k == j)
            {
                bestb = max(bestb, p[k] - p[last]);
                last = k;
            }
        last = i;
        for (int k = i + 1; k <= j; k++)
            if (c[k] == 'R' || k == j)
            {
                bestr = max(bestr, p[k] - p[last]);
                last = k;
            }
        ll kek = ans;
        if (b && r && bestb + bestr > p[j] - p[i] && i != 0 && j != n - 1)
            ans += 3 * (p[j] - p[i]) -  bestb - bestr;
        else
        {
            if (b)
            {
                ans += p[j] - p[i];
                int k = i;
                while (c[k] != 'B')
                    k++;
                if (i == 0)
                    ans -= p[k] - p[i];
                k = j;
                while (c[k] != 'B')
                    k--;
                if (j == n - 1)
                    ans -= p[j] - p[k];
                if (i != 0 && j != n - 1 && !r)
                    ans += p[j] - p[i] - bestb;
            }
            if (r)
            {
                ans += p[j] - p[i];
                int k = i;
                while (c[k] != 'R')
                    k++;
                if (i == 0)
                    ans -= p[k] - p[i];
                k = j;
                while (c[k] != 'R')
                    k--;
                if (j == n - 1)
                    ans -= p[j] - p[k];
                if (i != 0 && j != n - 1 && !b)
                    ans += p[j] - p[i] - bestr;
            }
            if (!b && !r)
            {
                if (i != 0 && j != n - 1)
                    ans += p[j] - p[i];
            }
        }
    //    cerr << ans - kek << endl;
        i = j;
    }
    cout << ans << endl;
    return 0;
}