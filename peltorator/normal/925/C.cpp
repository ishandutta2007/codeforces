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

const int LG = 61;
const int N = 100001;

int go[LG][N];

int find(int num, int bit)
{
    if (num == -1)
        return -1;
    return ((go[bit][num] == num ? num : (go[bit][num] = find(go[bit][num], bit))));
}

vector<int> pr, nxt;
vector<ll> b;
vector<ll> a, kek;

int beg, ending;

void add(int k, int prev)
{
    int nextpos = beg;
    if (prev != -1)
        nextpos = nxt[prev];
    if (nextpos != -1)
        pr[nextpos] = k;
    if (prev != -1)
        nxt[prev] = k;
    pr[k] = prev;
    nxt[k] = nextpos;
    for (ll i = 0; i < LG; i++)
    {
        if ((b[k] & (1LL << i)))
            go[i][k] = k;
        else
            go[i][k] = nextpos;
        if (prev != -1 && !(b[prev] & (1LL << i)))
            go[i][prev] = go[i][k];
    }
    if (nextpos == -1)
        ending = k;
    if (prev == -1)
        beg = k;
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    for (int i = 0; i < LG; i++)
        for (int j = 0; j < n; j++)
            go[i][j] = -1;
    b.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.rbegin(), b.rend());
   // for (int i = 0; i < n; i++)
    {
    //    for (int j = 5; j >= 0; j--)
      //      cout << ((b[i] >> (ll)j) & 1);
        //cout << endl;
    }
    pr.assign(n, -1);
    nxt.assign(n, -1);
    int i = 0;
    beg = -1;
    ending = -1;
    for (ll bit = 59; bit >= 0; bit--)
    {
        int j = i;
        while (j < b.size() && (b[j] & (1LL << bit)))
            j++;
        if (i == j)
            continue;
        if (i == 0 && i + 1 < j)
        {
            cout << "No" << endl;
         //   cout << bit << endl;
            return 0;
        }
        if (i == 0)
        {
            add(i, -1);
            i++;
            continue;
        }
        int cur = beg;
        while (i < j)
        {
            if (cur != -1)
                cur = find(cur, bit);
            if (cur != -1)
                add(i, pr[cur]);
            else
                add(i, ending);
            if (cur != -1)
                cur = nxt[cur];
            i++;
        }
    }
    ll cur = 0;
    while (beg != -1)
    {
        cur ^= b[beg];
        kek.push_back(b[beg]);
        a.push_back(cur);
        beg = nxt[beg];
    }
    for (int i = 1; i < a.size(); i++)
        if (a[i] <= a[i - 1])
        {
            cout << "No" << endl;
            return 0;
        }
    if (a.size() < n)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
        cout << kek[i] << ' ';
    cout << endl;
    return 0;
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