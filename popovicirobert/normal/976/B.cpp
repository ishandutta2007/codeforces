#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ll k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    if(k < n) {
        cout << 1 + k << " " << 1;
        return 0;
    }
    k -= n;
    ll x = k / (m - 1);
    if(x % 2 == 0) {
        cout << n - x << " " << 2 + k % (m - 1);
    }
    else {
        cout << n - x << " " << m - k % (m - 1);
    }
    //cin.close();
    //cout.close();
    return 0;
}