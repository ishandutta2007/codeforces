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
#include <iterator>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void dfs (const vector<pair<string, vector<int>>> &gr, vector<bool> &val, int v = 0)
{
    for (auto it : gr[v].second)
        dfs (gr, val, it);

    if (gr[v].first == "NOT")
        val[v] = !val[gr[v].second[0]];
    else if (gr[v].first == "AND")
        val[v] = val[gr[v].second[0]] & val[gr[v].second[1]];
    else if (gr[v].first == "OR")
        val[v] = val[gr[v].second[0]] | val[gr[v].second[1]];
    else if (gr[v].first == "XOR")
        val[v] = val[gr[v].second[0]] ^ val[gr[v].second[1]];
}

void push (const vector<pair<string, vector<int>>> &gr, const vector<bool> &val,
           vector<bool> &sence, int v = 0)
{
    sence[v] = true;

    if (gr[v].first == "NOT")
        push (gr, val, sence, gr[v].second[0]);
    else if (gr[v].first == "AND")
    {
        if (val[gr[v].second[0]] || val[gr[v].second[1]])
            for (auto it : gr[v].second)
                if (val[v] | !val[it])
                    push (gr, val, sence, it);
    }
    else if (gr[v].first == "OR")
    {
        if (!val[gr[v].second[0]] || !val[gr[v].second[1]])
            for (auto it : gr[v].second)
                if (!val[v] | val[it])
                    push (gr, val, sence, it);
    }
    else if (gr[v].first == "XOR")
        for (auto it : gr[v].second)
            push (gr, val, sence, it);
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<pair<string, vector<int>>> gr (n);
    vector<bool> val (n);

    vector<int> lists;

    for (int i = 0; i < gr.size (); i++)
    {
        cin >> gr[i].first;

        if (gr[i].first == "IN" || gr[i].first == "NOT")
        {
            int x;

            cin >> x;

            if (gr[i].first == "IN")
            {
                val[i] = x;
                lists.push_back (i);
            }
            else
                gr[i].second = {x - 1};
        }
        else
        {
            gr[i].second.resize (2);

            for (auto &it : gr[i].second)
            {
                cin >> it;
                it--;
            }
        }
    }

    dfs (gr, val);

    vector<bool> sence (n);

    push (gr, val, sence);

    string ans (lists.size (), '0' + val.front ());

    for (int i = 0; i < lists.size (); i++)
        ans[i] ^= sence[lists[i]];

    cout << ans << endl;
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