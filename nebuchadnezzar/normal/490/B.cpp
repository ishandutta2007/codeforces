#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;

int n;
set <pair <int, pair <int, int> > > s;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    vector <pair <int, int> > inp;
    set <int> s2;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        inp.puba(mapa(a, b));
        s.insert(mapa(a, mapa(b, i)));
        s2.insert(a);
    }

    for (int i = 0; i < n; ++i) {
        s2.erase(inp[i].ss);
    }

    vector <int> ans[2];
    int prev = 0;
    while (szof(s)) {
        pair <int, pair <int, int> > p = *s.lower_bound(mapa(prev, mapa(-1, -1)));
        if (p.ff != prev) {
            break;
        }
        //s2.erase(p.ff);
        //cout << p.ss.ss << endl;
        ans[0].puba(p.ss.ff);
        s.erase(p);
        prev = p.ss.ff;
        if (prev == 0) {
            break;
        }
    }
    prev = *s2.begin();
    while (szof(s)) {
        pair <int, pair <int, int> > p = *s.lower_bound(mapa(prev, mapa(-1, -1)));
        if (p.ff != prev) {
            break;
        }
        //s2.erase(p.ff);
        //cout << p.ss.ss << endl;
        ans[1].puba(p.ff);
        s.erase(p);
        prev = p.ss.ff;
        if (prev == 0) {
            break;
        }
    }
    if (n % 2) {
        ans[1].puba(prev);
    }
    vector <int> aans;
    aans.resize(n);

    for (int i = 0; i < szof(ans[0]); ++i) {
        aans[i * 2 + 1] = ans[0][i];
    }

    for (int i = 0; i < szof(ans[1]); ++i) {
        aans[i * 2] = ans[1][i];
    }
    for (int i = 0; i < n; ++i) {
        cout << aans[i] << " ";
    }
    cout << endl;

    return 0;
}