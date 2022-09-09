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
const int MAXN = 1e6 + 5;

int n, arr[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 2; i < MAXN; ++i) {
        if (!arr[i]) {
            for (int j = i * 2; j < MAXN; j += i) {
                arr[j] = true;
            }
        }
        //cout << i << " " << arr[i] << endl;
    }

    for (int i = 4; i < n; ++i) {
        if (arr[i] && arr[n - i]) {
            cout << i << " " << n - i << endl;
            return 0;
        }
    }

    return 0;
}