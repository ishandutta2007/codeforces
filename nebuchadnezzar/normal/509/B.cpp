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
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
const int MAXN = 105;

int n, k;

int inp[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;

    int mi = 100500, ma = 0;
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
        mi = min(mi, inp[i]);
        ma = max(ma, inp[i]);
    }

    if (ma - mi > k) {
        cout << "NO\n";
        return 0;
    }

    vector <int> tmp;

    for (int i = 0; i < ma - k + 1; ++i) {
        tmp.puba(1);
    }

    for (int i = 1; i < k; ++i) {
        tmp.puba(i + 1);
    }

    cout << "YES\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < inp[i]; ++j) {
            cout << tmp[j] << " ";
        }
        cout << endl;
    }

    return 0;
}