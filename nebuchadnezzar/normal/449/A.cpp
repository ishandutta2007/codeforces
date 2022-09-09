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
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;

int random() {
    return (rand() << 15) + rand();
}

long long n, m, k;

int main() {    
    cin >> n >> m >> k;
    if (n - 1 + m - 1 < k) {
        cout << -1;
        return 0;   
    }

    cout << max((n / (min(n - 1, k) + 1)) * (m / (k - min(n - 1, k) + 1)), (m / (min(m - 1, k) + 1)) * (n / (k - min(m - 1, k) + 1)));

    return 0;
}