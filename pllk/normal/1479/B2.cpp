#include <iostream>

using namespace std;

int n;
int a[101010];
int p[101010];
int d[101010];
int f[101010];

int main() {
    cin >> n;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[j];
        if (a[j] != a[j-1]) j++;
    }
    int k = j-1;
    int r = 0;
    for (int i = 1; i <= k; i++) {
        int e = p[a[i]];
        d[i] = d[i-1];
        if (e) {
            int u = 1+d[e+1];
            d[i] = max(d[i],u);
        }
        p[a[i]] = i;
        r = max(r,d[i]);
        // cout << i << " " << d[i] << "\n";
    }
    cout << k-r << "\n";
}