#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline int sum(ll x) {
    int ans = 0;
    while(x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    ll n;
    ios::sync_with_stdio(false);
    cin >> n;
    if(n < 10) {
        cout << n;
        return 0;
    }
    ll x = 0;
    while(x * 10 + 9 <= n) {
        x *= 10;
        x += 9;
    }
    cout << sum(x) + sum(n - x);
    //cin.close();
    //cout.close();
    return 0;
}