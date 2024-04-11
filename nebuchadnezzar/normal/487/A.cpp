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

int ay, dy, hy, am, dm, hm, a, d, h;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;

    int ans = 0;

    int bans = 1e9 + 5;
    for (int i = 0; i <= 300; ++i) {
        for (int j = 0; j <= 300; ++j) {
            for  (int k = 0; k <= 1000; ++k) {
                int tmp1 = max(0, ay + i - dm);
                int tmp2 = max(0, am - dy - j);
                if (tmp1 != 0 && (tmp2 == 0 || (hm + tmp1 - 1) / tmp1 < (hy + k + tmp2 - 1) / tmp2)) {
                    bans = min(bans, i * a + j * d + k * h);
                }
            }
        }
    }
    cout << bans << endl;
    
    return 0;
}