#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    ll n, t;
    ios::sync_with_stdio(false);
    cin >> n >> t;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        sum += x;
        if(t <= i * 86400 - sum) {
            cout << i;
            return 0;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}