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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll t;
    cin >> n;
    vector<int> a(n), ps(n + 1);
    int ce[2] = {1, 0}, s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        for (int j = 0; j < 62; j++)
            if (t & (1ll << j))
                a[i]++;
        ps[i + 1] = ps[i] + a[i];
        s += t;
        ans += ce[ps[i + 1] % 2];
        ce[ps[i + 1] % 2]++;
        int cmx = 0;
        for (int j = i; j >= max(0, i - 64); j--) {
            cmx = max(cmx, a[j]);
            if ((ps[i + 1] - ps[j]) % 2 == 0 && cmx * 2 > ps[i + 1] - ps[j])
                ans--;
        }
    }
    cout << ans;
}