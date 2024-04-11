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
    //int ;
    ll n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(n >= k) {
        cout << (k - 1) / 2;
    }
    else {
        if(2 * n - 1 >= k) {
            cout << n - k / 2;
        }
        else {
            cout << 0;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}