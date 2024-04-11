#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    ll k;
    ios::sync_with_stdio(false);
    cin >> k;
    if(k > 2 * 18) {
        cout << -1;
        return 0;
    }
    while(k > 1) {
        k -= 2;
        cout << 8;
    }
    if(k == 1)
        cout << 4;
    //cin.close();
    //cout.close();
    return 0;
}