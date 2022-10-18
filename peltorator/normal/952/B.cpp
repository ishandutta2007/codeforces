#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>

#define sz(a) (int)((a).size())

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

int solve()
{
    ios::sync_with_stdio(0);
    vector<int> a(10);
    for (int i = 0; i < 10; i++)
        a[i] = i;
    random_shuffle(a.begin(), a.end());
    int tau = 0;
    for (int i : a)
    {
        cout << i << endl;
        string s;
        getline(cin, s);
        if (s == "cool" || s == "not bad" || s == "don't think so" || s == "don't touch me" || s == "great")
        {
            cout << "normal" << endl;
            return 1;
        }
        else if (s != "no")
        {
            cout << "grumpy" << endl;
            return 1;
        }
        tau++;
        if (tau == 4)
        {
            break;
        }
    }
    cout << "grumpy" << endl;
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}