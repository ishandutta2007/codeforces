#include <iostream>
#include <string>
#include <vector>
#define int long long
using namespace std;
int sum(int x){
    int ans = 0;
    while (x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
signed main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector <int> ans;
    for (int i = 1; i <= 81; ++i){
        int res = i;
        for (int j = 1; j < a; ++j) res *= i;
        res = b * res + c;
        if (sum(res) == i and res < 1e9 and res > 0)
            ans.push_back(res);
    }
    cout << ans.size() << "\n";
    for (auto x: ans) cout << x << ' ';
    return 0;
}