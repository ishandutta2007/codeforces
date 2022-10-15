#include <iostream>

using namespace std;

typedef long long ll;

int n, m;
int a[101010];
int b[101010];

int main() {
    cin >> n >> m;
    ll s = 0;
    int v = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (a[i] > n-i+1) {
            cout << "-1\n";
            return 0;
        }
        s += a[i];
        v = max(v,i+a[i]-1);
    }
    if (s < n) {
        cout << "-1\n";
        return 0;
    }
    int p = n-v;
    int k = 1;
    for (int i = 1; i <= m; i++) {
        cout << k << " ";
        k++;
        if (p > 0) {
            int r = min(a[i]-1,p);
            k += r;
            p -= r;
        }
    }
    cout << "\n";
}