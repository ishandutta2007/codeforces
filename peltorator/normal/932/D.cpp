#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <memory.h>
#include <map>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define deb(a) cerr << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;

const int N = 400001, LG = 23;

ll w[N];
int lvl[N];
pair<ll, int> binup1[LG][N], binup2[LG][N];

int main()
{
  //  freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int q;
    cin >> q;
    ll last = 0;
    int n = 1;
    for (int i = 0; i < LG; i++)
    {
        binup1[i][1] = {0, 1};
        binup2[i][1] = {-1, -1};
    }
    lvl[1] = 1;
    for (int ui = 0; ui < q; ui++)
    {
        ll type, p, q;
        cin >> type >> p >> q;
        ll a = (p ^ last);
        ll b = (q ^ last);
//        cout << type << " " << a << " " << b << endl;
        if (type == 1)
        {
            n++;
            w[n] = b;
            lvl[n] = lvl[a] + 1;
            binup1[0][n] = {max(w[n], w[a]), a};
            for (int i = 1; i < LG; i++)
                binup1[i][n] = {max(binup1[i - 1][n].first, binup1[i - 1][binup1[i - 1][n].second].first), binup1[i - 1][binup1[i - 1][n].second].second};
            int v = binup1[0][n].second;
            for (int i = LG - 1; i >= 0; i--)
                if (binup1[i][v].first < w[n])
                    v = binup1[i][v].second;
            if (w[v] < w[n])
                v = binup1[0][v].second;
            if (w[v] >= w[n])
            {
                binup2[0][n] = {w[n], v};
                for (int i = 1; i < LG; i++)
                    if (binup2[i - 1][n].second != -1)
                        binup2[i][n] = {binup2[i - 1][n].first + binup2[i - 1][binup2[i - 1][n].second].first, binup2[i - 1][binup2[i - 1][n].second].second};
                    else
                        binup2[i][n] = {-1, -1};
            }
            else
                for (int i = 0; i < LG; i++)
                    binup2[i][n] = {-1, -1};
        }
        else
        {
            if (w[a] > b)
                last = 0;
            else
            {
                last = 0;
                for (int i = LG - 1; i >= 0; i--)
                    if (binup2[i][a].second != -1 && binup2[i][a].first <= b)
                    {
                        b -= binup2[i][a].first;
                        last += (1 << i);
                        a = binup2[i][a].second;
                    }
                if (b >= w[a])
                    last++;
            }
            cout << last << "\n";
        }
    }
    return 0;
}