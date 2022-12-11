#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int K = 500;

int a[MAXN];
int b[MAXN];
int num[MAXN];
int ind[MAXN];

vector<int> t[1000];

int n;

int x, y;

void rebuild(int i)
{
    vector<int> cur;
    for (auto el : t[ind[i]])
    {
        if (el == a[x])
        {
            cur.push_back(a[y]);
        }
        else if (el == a[y])
        {
            cur.push_back(a[x]);
        }
        else
        {
            cur.push_back(el);
        }
    }
    sort(cur.begin(), cur.end());
    t[ind[i]] = cur;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        num[a[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        a[i] = num[b[i]];
    }
    for (int i = 0; i < n; ++i)
    {
        ind[i] = i / K;
        t[ind[i]].push_back(a[i]);
    }
    ind[n] = ind[n - 1];
    for (int i = 0; i < 1000; ++i)
    {
        sort(t[i].begin(), t[i].end());
    }
    for (int i = 0; i < q; ++i)
    {
        int tt;
        cin >> tt;
        if (tt == 1)
        {
            int l, r;
            cin >> x >> y >> l >> r;
            ++y;
            --l;
            int ind1 = ind[l];
            int ind2 = ind[r];
            if (ind1 == ind2)
            {
                int ans = 0;
                for (int i = l; i < r; ++i)
                {
                    if (a[i] >= x && a[i] < y)
                    {
                        ++ans;
                    }
                }
                cout << ans << "\n";
            }
            else
            {
                int ans = 0;
                for (int i = l; i < (ind1 + 1) * K; ++i)
                {
                    if (a[i] >= x && a[i] < y)
                    {
                        ++ans;
                    }
                }
                for (int i = ind1 + 1; i < ind2; ++i)
                {
                    ans += lower_bound(t[i].begin(), t[i].end(), y) - lower_bound(t[i].begin(), t[i].end(), x);
                }
                for (int i = ind2 * K; i < r; ++i)
                {
                    if (a[i] >= x && a[i] < y)
                    {
                        ++ans;
                    }
                }
                cout << ans << "\n";
            }
        }
        else
        {
            cin >> x >> y;
            --x; --y;
            swap(a[x], a[y]);
            rebuild(x);
            if (ind[x] != ind[y])
            {
                rebuild(y);
            }
        }
    }
    return 0;
}