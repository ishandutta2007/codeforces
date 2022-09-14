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
    vector<ll> ans(n);
    vector<pair<ll, ll>> e;
    ll x, y;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x, &y);
        e.push_back({x, 1});
        e.push_back({y + 1, -1});
    }
    sort(e.begin(), e.end());
    ll l = -1, s = 0;
    for (auto &p : e) {
        if (s)
            ans[s - 1] += p.first - l;
        l = p.first;
        s += p.second;
    }
    for (ll i : ans)
        printf("%lld ", i);

}