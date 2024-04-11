#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> t;

int a[100];
int h[100];
bool ok;
int y;

void haku(int k) {
    if (ok) return;
    if (t[k] == 1) {
        int s = 0;
        for (int i = 0; i < k; i++) s += h[i];
        if (s == y) ok = true;
        return;
    }
    for (int i = 0; i < k; i++) {
        if (a[i] == t[k]) continue;
        if (h[i]-t[k] < 0) continue;
        h[i] -= t[k];
        a[k] = t[k]-1;
        h[k] = t[k]-1;
        haku(k+1);
        h[i] += t[k];
    }
}

int main() {
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) y++;
        if (t[i] == 2) {
            cout << "NO\n";
            return 0;
        }
    }
    if (y*2 < n) {
        cout << "NO\n";
        return 0;
    }
    sort(t.rbegin(), t.rend());
    a[0] = t[0]-1;
    h[0] = t[0]-1;
    haku(1);
    if (t[0] == 1 && n == 1) ok = true;
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}