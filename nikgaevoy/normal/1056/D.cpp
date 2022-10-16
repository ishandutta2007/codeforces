#ifdef LOCAL
#include "stdafx.h"
#else
#include <bits/stdc++.h>
#endif // LOCAL


using namespace std;


mt19937 mt (736);


int dfs (const vector<vector<int>> &gr, vector<int> &cnt, int v = 0)
{
    if (gr[v].empty ())
        cnt[v]++;

    for (auto it : gr[v])
        cnt[v] += dfs (gr, cnt, it);

    return cnt[v];
}


void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<vector<int>> gr (n);

    for (int i = 1; i < n; i++)
    {
        int t;

        cin >> t;
        t--;

        gr[t].push_back (i);
    }

    vector<int> cnt (n);

    dfs (gr, cnt);

    sort (cnt.begin (), cnt.end ());

    for (auto it : cnt)
        cout << it << ' ';
    cout << endl;
}


int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    ifstream fin ("input.txt");

    solve (fin);

    cout << setprecision (4) << "clock: " << clock () / (double)CLOCKS_PER_SEC << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}