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
    int n;
    scanf("%d", &n);
    vector<ll> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%lld", &a[i]);
    sort(a.begin(), a.end());
    ll ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    for (int i = 1; i < n; i++)
        ans = min(ans, (a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
    printf("%lld", ans);
}