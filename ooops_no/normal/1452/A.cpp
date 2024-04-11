#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int sum = a * 2;
        b -= a;
        if (b == 0){
            cout << sum << endl;
        }
        else{
            cout << sum + 1 + (b - 1) * 2 << endl;
        }
    }
    return 0;
}