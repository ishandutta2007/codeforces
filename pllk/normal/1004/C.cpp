#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[101010];
int z[101010];
int s[101010];
int lp[101010];
int rp[101010];
ll c;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1];
        if (z[a[i]]) continue;
        lp[a[i]] = i;
        s[i]++;
        z[a[i]] = 1;
    }
    for (int i = 1; i <= 100000; i++) z[i] = 0;
    for (int i = n; i >= 1; i--) {
        if (z[a[i]]) continue;
        rp[a[i]] = i;
        z[a[i]] = 1;
    }
    for (int i = 1; i <= 100000; i++) {
        if (!rp[i]) continue;
        int u = s[rp[i]-1];
        c += u;
    }
    cout << c << "\n";
}