#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[101010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a,a+n);
        int c = 0;
        int u = 0;
        for (int i = n-1; i >= 0; i--) {
            c++;
            if (a[i]*c >= x) {
                u++;
                c = 0;
            }
        }
        cout << u << "\n";
    }
}