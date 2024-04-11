#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int INF = 1e9 + 9;

int n;
vector <pii > inp;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        inp.puba(mapa(x, y));
    }

    int ans = INF;
    for (int i = 1; i <= 1000; ++i) {
        vector <int> v;
        bool flag = true;
        int t = 0;
        int used = 0;
        for (int j = 0; j < n; ++j) {
            if (min(inp[j].ff, inp[j].ss) > i) {
                flag = false;
                break;
            }
            if (inp[j].ss > i) {
                t += inp[j].ss;
                used++;
            } else if (inp[j].ff > i) {
                t += inp[j].ff;
            } else if (inp[j].ff <= inp[j].ss) {
                t += inp[j].ff;
            } else {
                v.puba(inp[j].ff - inp[j].ss);
                t += inp[j].ff;
            }
        }
        sort(bend(v));
        reverse(bend(v));
        for (int j = 0; (j + used + 1) * 2 <= n && j < szof(v); ++j) {
            t -= v[j];
        }
        if (used * 2 <= n && flag) {
            ans = min(ans, i * t);
        }
    }

    cout << ans << endl;
    return 0;
}