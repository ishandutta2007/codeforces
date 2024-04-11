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


int a, b, c;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> a >> b >> c;

    cout << max(a * b * c, max(a * b + c, max(a * (b + c), max(a + b * c, max(a + b + c, (a + b) * c))))) << endl;
    return 0;
}