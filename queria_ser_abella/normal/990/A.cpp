#include <iostream>
#define ll long long

using namespace std;

int main() {
    ll n,d,a,b;
    cin >> n >> d >> a >> b;
    ll up = n/d;
    if(n%d) up++;
    up *= d;
    ll ans = (up-n) * a;
    ll down = (n/d)*d;
    ans = min(ans,(n-down)*b);
    cout << ans << endl;
}