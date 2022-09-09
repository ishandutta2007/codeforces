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
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;
const int MAXN = 5005;

int n;
int a[MAXN], b[MAXN];
vector <pair <int, int> > timeline;
bool done[MAXN];

bool comp(pair <int, int> n1, pair <int, int> n2) {
    if (n1.ff != n2.ff) {
        return n1.ff < n2.ff;
    }
    return a[n1.ss] < a[n2.ss];
}   

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        timeline.puba(mapa(a[i], i));
        timeline.puba(mapa(b[i], i));
    }
    sort(all(timeline), comp);

    int ans = 0;
    for (int i = 0; i < szof(timeline); ++i) {
        //cout << timeline[i].ff << " " << timeline[i].ss << endl;
        if (done[timeline[i].ss]) {
            continue;
        }
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (!done[j] && a[j] < a[timeline[i].ss]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            //cout << "+" << endl;
            done[timeline[i].ss] = true;
            ans = timeline[i].ff;
        }
    }
    cout << ans << endl;
    return 0;
}