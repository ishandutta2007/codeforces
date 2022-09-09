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

int n;
vector <int> v;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    v.puba(0);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        v.puba(v[szof(v) - 1] + num);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        cout << lower_bound(all(v), num) - v.begin() << endl;
    }

    return 0;
}