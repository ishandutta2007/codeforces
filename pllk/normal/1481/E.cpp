#include <iostream>

using namespace std;

int n;
int a[505050];
int pl[505050];
int pr[505050];
int c[505050];
int d[505050];
int e[505050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        c[i] = c[pr[a[i]]]+1;
        if (!pl[a[i]]) pl[a[i]] = i;
        pr[a[i]] = i;
    }
    int r = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = d[i-1];
        if (pr[a[i]] == i) {
            d[i] = max(d[i],d[pl[a[i]]-1]+c[i]);
        }
        r = max(r,d[i]);
        e[a[i]] = max(e[a[i]],d[i-1]+1-c[i]);
        r = max(r,e[a[i]]+c[i]);
    }
    cout << n-r << "\n";
}