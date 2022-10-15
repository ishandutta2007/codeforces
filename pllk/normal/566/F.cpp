#include <iostream>

using namespace std;

int n;
int c[1010101];
int d[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[x] = 1;
        d[x] = 1;
    }
    int t = 1;
    for (int i = 1; i <= 1000000; i++) {
        if (!c[i]) continue;
        for (int j = 2*i; j <= 1000000; j += i) {
            if (!c[j]) continue;
            d[j] = max(d[j],d[i]+1);
            t = max(t,d[j]);
        }
    }
    cout << t << "\n";
}