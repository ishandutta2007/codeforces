#include <bits/stdc++.h>
#define ll long long

using namespace std;




int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    ll l, r, x, y, k;
    ios::sync_with_stdio(false);
    cin >> l >> r >> x >> y >> k;
    for(int i = l; i <= r; i++) {
        if(i % k == 0 && i / k >= x && i / k <= y) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}