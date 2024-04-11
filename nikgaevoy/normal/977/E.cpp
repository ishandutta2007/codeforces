#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void dfs (const vector<vector<int>> &gr, vector<int> &col, int v, int c)
{
    if (col[v] != -1)
        return;

    col[v] = c;

    for (auto it : gr[v])
        dfs (gr, col, it, c);
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> gr (n);

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;
        a--;
        b--;

        gr[a].push_back (b);
        gr[b].push_back (a);
}

    vector<int> col (n, -1);

    for (int i = 0; i < gr.size (); i++)
        dfs (gr, col, i, i);

    unordered_set<int> cand (col.begin (), col.end ());

    for (int i = 0; i < gr.size (); i++)
        if (gr[i].size () != 2)
            cand.erase (col[i]);

    cout << cand.size () << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}