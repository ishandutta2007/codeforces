#include <iostream>
 typedef long long ll;
 const ll mod = (ll)1e9+7;
 using namespace std;
int main() {
    ll a, b; 
    while (cin >> a >> b) {
        ll answ = 0;
        for (ll r = 1; r < b; ++r) {
            answ = (answ + a * r + (a+1) * a % mod * ((mod+1)/2) % mod * r % mod * b % mod) % mod;
        }
        cout << answ << endl;
    }
    return 0;
}