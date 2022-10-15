#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int n;
ll k, x;
ll a[202020];
vector<ll> d;

int main() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    for (int i = 1; i < n; i++) {
        if (a[i]-a[i-1] > x) {
            d.push_back((a[i]-a[i-1]-1)/x);
        }
    }
    sort(d.begin(),d.end());
    int r = d.size()+1;
    for (auto x : d) {
        if (k >= x) {
            k -= x;
            r--;
        }
    }
    cout << r << "\n";
}