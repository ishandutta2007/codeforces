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
typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, t;
    scanf("%d", &n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        m[t]++;
    }
    int s = 0, ans = 0;
    for (auto p : m) {
        t = min(p.second, s);
        s += p.second - t;
        ans += t;
    }
    printf("%d", ans);
}