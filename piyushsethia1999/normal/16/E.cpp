#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

void traverse(std::vector<double>& gr, int n, std::vector<std::vector<double> >& a)
{
    queue<int> q;
    q.push((1 << n) - 1);
    std::vector<bool> vis(1 << n, false);
    while (!q.empty()) {
        int topstate = q.front();
        q.pop();
        if (!vis[topstate])
        {
            vis[topstate] = true;
            std::vector<int> rem;
            for (int i = 0; i < n; ++i)
                if (topstate & (1 << i))
                    rem.pb(i);
            int si = rem.size();
            if (si > 1)
                for (int i : rem)
                {
                    double tr = 0;
                    for (int j : rem)
                        tr += a[j][i];
                    tr = ((2.0 * tr) / (((double)(si)) * ((double)(si - 1))));
                    gr[(topstate) & (~(1 << i))] += (gr[topstate] * tr);
                    q.push((topstate) & (~(1 << i)));
                }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    vector<std::vector<double> > a(n, std::vector<double> (n)); for (int o = 0; o < n; o++) for (int j = 0; j < n; ++j) cin >> a[o][j];
    std::vector<double> gr(1 << n, 0);
    gr[(1 << (n)) - 1] = 1;
    traverse(gr, n, a);
    for (int i = 0; i < n; ++i)
        cout << gr[(1 << i)] << " ";
}