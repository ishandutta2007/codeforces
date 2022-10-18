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

void st(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        while (a[i] >= a[i - 1] + 2)
            a[i]--, a[i - 1]++;
        while (a[i] + 2 <= a[i - 1])
            a[i - 1]--, a[i]++;
    }
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i + 1 < n; i++)
        if (a[i] >= a[i - 1] + 2 && a[i] >= a[i + 1] + 2)
        {
            cout << "NO\n";
            return 1;
        }
    vector<int> b = a;
    sort(b.begin(), b.end());
    st(a);
    vector<int> c;
    while (a.size())
    {
        int ind = 0;
        for (int i = 1; i < a.size(); i++)
            if (a[i] > a[ind])
                ind = i;
        c.push_back(a[ind]);
        for (int i = ind + 1; i < a.size(); i++)
            a[i - 1] = a[i];
        a.pop_back();
        st(a);
        st(c);
    }
    vector<int> q = b;
    reverse(q.begin(), q.end());
    cout << (c == b || q == c ? "YES\n" : "NO\n");

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