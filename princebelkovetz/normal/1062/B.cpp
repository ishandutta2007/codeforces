#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
    int n; cin >> n;
    vector <pair <int, int>> a;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) a.push_back({i, 0});
        while (n % i == 0){
            n /= i;
            a.back().second++;
        }
    }
    if (n != 1) a.push_back({n, 1});
    int ans = 1, res = 0, mx = 0;
    for (auto x: a){
        ans *= x.first;
        mx = max(mx, x.second);
    }
    int sz = 1;
    while (sz < mx) {
        sz *= 2;
    }
    int cnt = 0;
    for (auto x: a){
        cnt += x.second != sz;
    }
    if (cnt){
        res++;
    }
    while (sz > 1){
        res++;
        sz /= 2;
    }
    
    cout << ans << ' ' << res << '\n';
    
    return 0;
}