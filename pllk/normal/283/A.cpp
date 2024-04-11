#include <iostream>
#include <iomanip>

#define lli long long int

using namespace std;

lli s[200000+1];
lli d[200000+1];
lli f;
int p = 1;
int t, a, x, k;

int n;

int main() {
    cin >> n;
    cout << setprecision(9);
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 1) {
            cin >> a >> x;
            f += a*x;
            d[a-1] += x;
        }
        if (t == 2) {
            cin >> k;
            s[p++] = k;
            f += k;
        }
        if (t == 3) {
            p--;
            f -= (s[p]+d[p]);
            d[p-1] += d[p];
            d[p] = 0;
        }
        cout << 1.0*f/p << endl;
    }
}