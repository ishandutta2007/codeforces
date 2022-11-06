#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, char> edges;
    int same = 0;
    int edge = 0;
    while (m--)
    {
        char type;
        cin >> type;
        if (type == '+')
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            edges[{u, v}] = c;
            if (edges.count({v, u}))
            {
                edge++;
                if (edges[{v, u}] == c)
                    same++;
            }
        }
        else if (type == '-')
        {
            int u, v;
            cin >> u >> v;
            if (edges.count({v, u}))
            {
                edge--;
                if (edges[{v, u}] == edges[{u, v}])
                    same--;
            }
            edges.erase({u, v});
        }
        else
        {
            int k;
            cin >> k;
            if (k & 1)
                cout << (edge ? "YES" : "NO") << "\n";
            else
                cout << (same ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}