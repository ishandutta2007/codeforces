#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        ans += (n + m) * 2 - 4;
        n -= 4;
        m -= 4;
    }
    cout << ans;
}