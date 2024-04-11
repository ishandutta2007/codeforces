#pragma comment(linker,"/STACK:200000000")

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <random>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

const string filename = "tree40";
bool interactive = true;
const int inf = 1e9 + 7;

int dfs (vector<vector<int>> &gr, int st)
{
    static vector<bool> used (gr.size ());

    if (used[st])
        return 0;

    used[st] = true;

    int ans = 1;

    for (auto it : gr[st])
        ans += dfs (gr, it);

    return ans;
}

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    int n, m, k;

    cin >> n >> m >> k;

    vector<int> cap (k);

    for (auto &it : cap)
        cin >> it;

    sort (cap.begin (), cap.end ());

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

    vector<int> siz (cap.size ());

    for (int i = 0; i < siz.size (); i++)
        siz[i] = dfs (gr, --cap[i]);

    sort (siz.begin (), siz.end ());

    long long ans = 0;
    int sum = 0;

    for (auto it : siz)
        sum += it;

    siz.back () += n - sum;

    for (auto it : siz)
        ans += it * (long long) (it - 1) / 2;

    cout << ans - m << endl;

    return 0;
}