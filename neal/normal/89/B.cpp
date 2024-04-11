#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

enum widget_type {HORIZ, VERT, NONE};

struct widget
{
    string name;
    long long width, height;
    int border, spacing;
    vector <string> packed;
    widget_type type;

    inline widget ()
    {
        width = height = 0;
        border = spacing = 0;
        packed.clear ();
        type = NONE;
    }
};

map <string, widget> mapping;
map <string, pair <long long, long long> > solved;

inline pair <long long, long long> get_size (widget w)
{
    if (solved.find (w.name) != solved.end ())
        return solved [w.name];

    pair <long long, long long> &sol = solved [w.name] = make_pair (0, 0);

    if (w.packed.empty ())
        return sol = make_pair (w.width, w.height);
    else
    {
        assert (w.type != NONE);
        int n = w.packed.size ();

        if (w.type == HORIZ)
        {
            sol.first = 2 * w.border + (n - 1) * w.spacing;
            sol.second = 0;
        }
        else
        {
            sol.first = 0;
            sol.second = 2 * w.border + (n - 1) * w.spacing;
        }

        for (int i = 0; i < n; i++)
        {
            pair <long long, long long> p = get_size (mapping [w.packed [i]]);

            if (w.type == HORIZ)
            {
                sol.first += p.first;
                sol.second = max (sol.second, 2 * w.border + p.second);
            }
            else
            {
                sol.first = max (sol.first, 2 * w.border + p.first);
                sol.second += p.second;
            }
        }

        return sol;
    }
}

int main ()
{
    int N; cin >> N;

    for (int n = 1; n <= N; n++)
    {
        string line;

        do
            getline (cin, line);
        while (line.length () == 0);

        for (int i = 0; i < (int) line.length (); i++)
            if (line [i] == '.' || line [i] == ',' || line [i] == '(' || line [i] == ')')
                line [i] = ' ';

        string name, name2;
        widget w;
        istringstream input (line);
        string op;
        input >> op;

        if (op == "Widget")
        {
            input >> w.name >> w.width >> w.height;
            mapping [w.name] = w;
        }
        else if (op == "HBox")
        {
            input >> w.name;
            w.type = HORIZ;
            mapping [w.name] = w;
        }
        else if (op == "VBox")
        {
            input >> w.name;
            w.type = VERT;
            mapping [w.name] = w;
        }
        else
        {
            name = op;
            input >> op;

            if (op == "pack")
            {
                input >> name2;
                mapping [name].packed.push_back (name2);
            }
            else if (op == "set_border")
                input >> mapping [name].border;
            else if (op == "set_spacing")
                input >> mapping [name].spacing;
            else
                cerr << "FAILED on line " << n << "!\n";
        }
    }

    for (map <string, widget> :: iterator it = mapping.begin (); it != mapping.end (); it++)
    {
        pair <long long, long long> p = get_size (it->second);
        cout << it->first << ' ' << p.first << ' ' << p.second << '\n';
    }

    return 0;
}