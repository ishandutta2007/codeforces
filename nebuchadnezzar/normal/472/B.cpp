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

int n, k;
vector <int> v;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        v.puba(num);
    }

    sort(all(v));

    LL ans = 0;

    for (int i = n - 1; i  >= 0; i -= k) {
        ans += (v[i] - 1) * 2;
        //cout << v[i] << endl;
    }
    
    cout << ans;

    return 0;
}