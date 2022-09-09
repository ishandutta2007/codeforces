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

int w, h, n;

set <int> va, ha;
set <pii > wah, wav;


int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> w >> h >> n; 

    va.insert(0);
    va.insert(w);
    ha.insert(0);
    ha.insert(h);
    wah.insert(mapa(h, 0));
    wav.insert(mapa(w, 0));

    for (int i = 0; i < n; ++i) {
        char ch;
        int num;
        cin >> ch >> num;
        if (ch == 'V') {
            int le = *(--va.lower_bound(num));
            int mo = *(va.upper_bound(num));
            wav.erase(mapa(mo - le, le));
            wav.insert(mapa(mo - num, num));
            wav.insert(mapa(num - le, le));
            va.insert(num);
        } else {
            int le = *(--ha.lower_bound(num));
            int mo = *(ha.upper_bound(num));
            wah.erase(mapa(mo - le, le));
            wah.insert(mapa(mo - num, num));
            wah.insert(mapa(num - le, le));
            ha.insert(num);
        }
        cout << ((LL)(--wah.end()) -> ff) * (LL) (--wav.end()) -> ff << "\n";
    }

    return 0;
}