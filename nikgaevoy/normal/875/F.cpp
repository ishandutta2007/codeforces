#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>
#include <vector>
#include <unordered_map>
#include <functional>

#include <cassert>

using namespace std;

class dsu
{
    vector<int> par, siz;

public:
    dsu (int n) : par (n, -1), siz (n, 1)
    {}

    int get_group (int v)
    {
        if (par[v] == -1)
            return v;

        return par[v] = get_group (par[v]);
    }

    bool unite (int a, int b)
    {
        a = get_group (a);
        b = get_group (b);

        if (a == b)
            return false;

        if (siz[a] < siz[b])
            swap (a, b);

        par[b] = a;
        siz[a] += siz[b];

        return true;
    }
};

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, m;
    
    cin >> n >> m;

    vector<vector<int>> princesses (m, vector<int> (3));

    for (auto &row : princesses)
    {
        cin >> row[1] >> row[2] >> row[0];
        row[1]--;
        row[2]--;
    }

    sort (princesses.begin (), princesses.end (), greater<vector<int>> ());

    long long ans = 0;
    dsu princes (n + 1);

    for (auto it : princesses)
        if (princes.unite (it[1], it[2]) ||
            princes.unite (it[1], n))
            ans += it[0];

    cout << ans << endl;

    return 0;
}