#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
    std::vector<int> va(1000001, 0);
    va[0] = 1;
    int sn = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; ++i)
    {
        set<int> s1;
        for (int j = 1; j * j <= a[i]; ++j)
        {
            if (a[i] % j == 0)
            {
                s1.insert(j);
                if (j * j != a[i])
                    s1.insert(a[i] / j);
            }
        }
        auto it = s1.rbegin();
        auto ik = s1.rend();
        for (; it != ik ; ++it)
        {
            int ij = *it;
            va[(ij)] = va[(ij)] + va[(ij) - 1];
            if (va[ij] > mod)
                va[ij] -= mod;
        }
    }
    for (int i = 1; i <= 1000000; ++i)
    {
        sn = (sn + va[i]);
        if (sn > mod)
            sn -= mod;
    }
    cout << sn;
}