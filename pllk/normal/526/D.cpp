#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
string s;
int z[1010101];
int t[1010101];
int v[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cin >> s;
    int a = 0, b = 0;
    v[0] = -1;
    for (int i = 1; i < n; i++) {
        if (i > b) {
            z[i] = 0;
            for (int j = i; j < n; j++) {
                if (s[j-i] == s[j]) z[i]++;
                else break;
            }
        } else if (i+z[i-a] <= b) {
            z[i] = z[i-a];
        } else {
            z[i] = b-i+1;
            for (int j = b+1; j < n; j++) {
                if (s[j-i] == s[j]) z[i]++;
                else break;
            }
        }
        if (i+z[i]-1 > b) {
            a = i;
            b = i+z[i]-1;
        }
        v[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (k*i > n) break;
        bool ok = true;
        for (int j = i, c = 1; c < k; j += i, c++) {
            if (z[j] < i) {
                ok = false;
                break;
            }
        }
        if (ok) t[k*i-1] = 1;
        if (ok && k*i < n && z[k*i] > 0) {
            v[k*i] = k*i+min(i,z[k*i])-1;
        }
    }
    int u = -1;
    for (int i = 0; i < n; i++) {
        u = max(u, v[i]);
        if (u >= i) cout << 1;
        else cout << t[i];
    }
    cout << "\n";
}