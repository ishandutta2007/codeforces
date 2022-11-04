#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;


int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    //int ;
    ll l, r;
    ios::sync_with_stdio(false);
    cin >> l >> r;
    cout << "YES" << "\n";
    for(ll i = l; i < r; i += 2) {
        cout << i << " " << i + 1 << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}