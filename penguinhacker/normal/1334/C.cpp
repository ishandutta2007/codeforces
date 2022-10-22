#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
 
ll a[300000];
ll b[300000];
 
void doIt() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    ll bullets = 0;
    ll minSo = min(a[1], b[0]);
    for (int i = 0; i < n; ++i) {
        ll tmp = a[(i + 1) % n];
        bullets += (tmp - b[i] >0LL ? tmp-b[i] : 0LL);
        ll t = tmp < b[i] ? tmp : b[i];
        minSo = minSo<t ? minSo : t;
    }
    cout << bullets + minSo << endl;
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin >> t;
    while (t--) {
        doIt();
    }
}