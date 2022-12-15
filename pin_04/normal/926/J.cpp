#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 2e5 + 5;

set <pair <int, int>> s;
pair <int, int> a[N];

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l,r;
        cin >> l >> r;
        while (s.size())
        {
            auto it = s.lower_bound(mp(l, 0));
            if (it == s.begin()) break;
            it--;
            int u = (*it).fi;
            int v = (*it).se;
            if (v < l) break;
            l = u;
            r = max(r, v);
            s.erase(it);
        }
        while (s.size())
        {
            auto it = s.lower_bound(mp(l, 0));
            if (it == s.end()) break;
            int u = (*it).fi;
            int v = (*it).se;
            if (u > r) break;
            r = max(r, v);
            s.erase(it);
        }
        s.insert(mp(l, r));
        cout << s.size() << " ";
    }
    return 0;
}