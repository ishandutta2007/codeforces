#include <iostream>

using namespace std;

#define ll long long

int n, m, k;
int a[101010];
int b[101010];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    ll s = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s += b[x]/k+1;
        if (b[x] == 0) continue;
        int z = b[x];
        int q = a[z-1];
        swap(a[z-1],a[z]);
        b[x]--;
        b[q]++;
    }
    cout << s << "\n";
}