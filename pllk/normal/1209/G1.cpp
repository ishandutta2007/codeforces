#include <iostream>

using namespace std;

int n, q;
int a[202020];
int la[202020];
int cn[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        la[a[i]] = i;
        cn[a[i]]++;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        int x = la[a[i]];
        int mc = cn[a[i]];
        int cc = 0;
        for (int j = i; j <= x; j++) {
            x = max(x,la[a[j]]);
            cc++;
            mc = max(mc,cn[a[j]]);
        }
        c += cc-mc;
        i = x;
    }
    cout << c << "\n";
}