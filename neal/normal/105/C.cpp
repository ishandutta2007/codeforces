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

const int MAX = 1005;

struct item
{
    string name, type;
    int atk, def, res, size;
};

struct resident
{
    string name, type;
    int bonus;
    string home;
};

int N, K;
item items [MAX];
resident residents [MAX];
bool used [MAX];

int main ()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> items [i].name >> items [i].type >> items [i].atk >> items [i].def >> items [i].res >> items [i].size;

        if (items [i].type == "weapon")
            items [i].type = "atk";
        else if (items [i].type == "armor")
            items [i].type = "def";
        else if (items [i].type == "orb")
            items [i].type = "res";
        else
            assert (false);
    }

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> residents [i].name >> residents [i].type >> residents [i].bonus >> residents [i].home;

        if (residents [i].type == "gladiator")
            residents [i].type = "atk";
        else if (residents [i].type == "sentry")
            residents [i].type = "def";
        else if (residents [i].type == "physician")
            residents [i].type = "res";
        else
            assert (false);
    }

    int sum_size = 0;

    for (int i = 0; i < N; i++)
        sum_size += items [i].size;

    if (sum_size == K)
    {
        int atk_total = -1, def_total = -1, res_total = -1;
        int best_atk = -1, best_def = -1, best_res = -1;

        for (int i = 0; i < N; i++)
            if (items [i].type == "atk")
            {
                int total = items [i].atk;

                for (int j = 0; j < K; j++)
                    if (residents [j].home == items [i].name && residents [j].type == "atk")
                        total += residents [j].bonus;

                if (total > atk_total)
                {
                    atk_total = total;
                    best_atk = i;
                }
            }
            else if (items [i].type == "def")
            {
                int total = items [i].def;

                for (int j = 0; j < K; j++)
                    if (residents [j].home == items [i].name && residents [j].type == "def")
                        total += residents [j].bonus;

                if (total > def_total)
                {
                    def_total = total;
                    best_def = i;
                }
            }
            else if (items [i].type == "res")
            {
                int total = items [i].res;

                for (int j = 0; j < K; j++)
                    if (residents [j].home == items [i].name && residents [j].type == "res")
                        total += residents [j].bonus;

                if (total > res_total)
                {
                    res_total = total;
                    best_res = i;
                }
            }
            else
                assert (false);

        cout << items [best_atk].name;
        int reside = 0;

        for (int i = 0; i < K; i++)
            if (residents [i].home == items [best_atk].name)
                reside++;

        cout << ' ' << reside;

        for (int i = 0; i < K; i++)
            if (residents [i].home == items [best_atk].name)
                cout << ' ' << residents [i].name;

        cout << '\n';


        cout << items [best_def].name;
        reside = 0;

        for (int i = 0; i < K; i++)
            if (residents [i].home == items [best_def].name)
                reside++;

        cout << ' ' << reside;

        for (int i = 0; i < K; i++)
            if (residents [i].home == items [best_def].name)
                cout << ' ' << residents [i].name;

        cout << '\n';


        cout << items [best_res].name;
        reside = 0;

        for (int i = 0; i < K; i++)
            if (residents [i].home == items [best_res].name)
                reside++;

        cout << ' ' << reside;

        for (int i = 0; i < K; i++)
            if (residents [i].home == items [best_res].name)
                cout << ' ' << residents [i].name;

        cout << '\n';
        return 0;
    }

    vector <pair <int, int> > atk, def, res;

    for (int i = 0; i < K; i++)
        if (residents [i].type == "atk")
            atk.push_back (make_pair (residents [i].bonus, i));
        else if (residents [i].type == "def")
            def.push_back (make_pair (residents [i].bonus, i));
        else if (residents [i].type == "res")
            res.push_back (make_pair (residents [i].bonus, i));
        else
            assert (false);

    sort (atk.rbegin (), atk.rend ());
    sort (def.rbegin (), def.rend ());
    sort (res.rbegin (), res.rend ());

    int atk_total = -1, def_total = -1, res_total = -1;
    int best_atk = -1, best_def = -1, best_res = -1;

    for (int i = 0; i < N; i++)
        if (items [i].type == "atk")
        {
            int total = items [i].atk;

            for (int j = 0; j < min (items [i].size, (int) atk.size ()); j++)
                total += atk [j].first;

            if (total > atk_total)
            {
                atk_total = total;
                best_atk = i;
            }
        }
        else if (items [i].type == "def")
        {
            int total = items [i].def;

            for (int j = 0; j < min (items [i].size, (int) def.size ()); j++)
                total += def [j].first;

            if (total > def_total)
            {
                def_total = total;
                best_def = i;
            }
        }
        else if (items [i].type == "res")
        {
            int total = items [i].res;

            for (int j = 0; j < min (items [i].size, (int) res.size ()); j++)
                total += res [j].first;

            if (total > res_total)
            {
                res_total = total;
                best_res = i;
            }
        }

    vector <int> atk_answer, def_answer, res_answer;

    for (int i = 0; i < min (items [best_atk].size, (int) atk.size ()); i++)
    {
        atk_answer.push_back (atk [i].second);
        used [atk [i].second] = true;
    }

    for (int i = 0; i < min (items [best_def].size, (int) def.size ()); i++)
    {
        def_answer.push_back (def [i].second);
        used [def [i].second] = true;
    }

    for (int i = 0; i < min (items [best_res].size, (int) res.size ()); i++)
    {
        res_answer.push_back (res [i].second);
        used [res [i].second] = true;
    }

    while ((int) atk_answer.size () < items [best_atk].size)
    {
        int unused = -1;

        for (int i = 0; i < K; i++)
            if (!used [i])
                unused = i;

        if (unused == -1)
            break;

        atk_answer.push_back (unused);
        used [unused] = true;
    }

    while ((int) def_answer.size () < items [best_def].size)
    {
        int unused = -1;

        for (int i = 0; i < K; i++)
            if (!used [i])
                unused = i;

        if (unused == -1)
            break;

        def_answer.push_back (unused);
        used [unused] = true;
    }

    while ((int) res_answer.size () < items [best_res].size)
    {
        int unused = -1;

        for (int i = 0; i < K; i++)
            if (!used [i])
                unused = i;

        if (unused == -1)
            break;

        res_answer.push_back (unused);
        used [unused] = true;
    }

    cout << items [best_atk].name << ' ' << atk_answer.size ();

    for (int i = 0; i < (int) atk_answer.size (); i++)
        cout << ' ' << residents [atk_answer [i]].name;

    cout << '\n';


    cout << items [best_def].name << ' ' << def_answer.size ();

    for (int i = 0; i < (int) def_answer.size (); i++)
        cout << ' ' << residents [def_answer [i]].name;

    cout << '\n';


    cout << items [best_res].name << ' ' << res_answer.size ();

    for (int i = 0; i < (int) res_answer.size (); i++)
        cout << ' ' << residents [res_answer [i]].name;

    cout << '\n';

    return 0;
}