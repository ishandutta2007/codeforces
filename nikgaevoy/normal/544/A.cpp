#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const string filename = "sum";

int main ()
{
    //freopen ((filename + ".in").c_str (), "r", stdin);
    //freopen ((filename + ".out").c_str (), "w", stdout);

    ios_base::sync_with_stdio (false);

    int k;
    char s[256];
    cin >> k >> s;

    string str (s);

    set<char> w;
    vector<int> pos;

    for (int i = 0; pos.size() < k && i < str.size (); i++)
        if (w.count (str[i]) == 0)
        {
            w.insert (str[i]);
            pos.push_back (i);
        }

    if (pos.size () == k)
    {
        pos.push_back (str.size ());
        cout << "YES" << endl;
        for (int i = 0; i < k; i++)
            cout << str.substr (pos[i], pos[i + 1] - pos[i]).c_str () << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}