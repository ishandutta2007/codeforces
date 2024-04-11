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
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, sum = 0, ans;
    scanf("%lld%lld", &n, &m);
    vector<ll> a(n + 2), ps(n + 2);
    a[n + 1] = m;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 0; i < n + 1; i += 2) {
        ps[i + 1] = a[i + 1] - a[i];
    }
    for (int i = 1; i < n + 2; i++)
        ps[i] += ps[i - 1];
    ans = ps[n + 1];
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            if (a[i] + 1 < a[i + 1])
                ans = max(ans, ps[i] + m - a[i] - 1 - (ps[n + 1] - ps[i]));
            if (a[i - 1] + 1 < a[i])
                ans = max(ans, ps[i] - 1 + m - a[i] + 1 - (ps[n + 1] - ps[i] + 1));
        }
        else {
            if (a[i] + 1 < a[i + 1])
                ans = max(ans, ps[i] + 1 + m - a[i] - 1 - (ps[n + 1] - ps[i] - 1));
            if (a[i - 1] + 1 < a[i])
                ans = max(ans, ps[i] + m - a[i] + 1 - (ps[n + 1] - ps[i]));
        }
    }
    printf("%lld", ans);
}