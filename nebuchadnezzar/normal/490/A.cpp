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
vector <int> v[3];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        v[num - 1].puba(i);
    }

    int tmp = min(min(szof(v[0]), szof(v[1])), szof(v[2]));
    cout << tmp << endl;

    for (int i = 0; i < tmp; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << v[j][i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}