#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int n;
ll a[202020];
int m;
int c[202020];

vector<ll> z;
int w[202020];

void simu(int k, int s) {
    for (int i = 1; i <= n; i++) w[i] = c[i];
    ll u = 0;
    for (int i = 0; i < m-1; i++) {
        w[k]--;
        int v = k;
        if (s == 1) {
            if (k == n) {s = -1; k--;}
            else k++;
        } else if (s == -1) {
            if (k == 1) {s = 1; k++;}
            else k--;
        }
        u += abs(a[v-1]-a[k-1]);
    }
    w[k]--;
    for (int i = 1; i <= n; i++) if (w[i] != 0) return;
    z.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    simu(1, 1);
    simu(n, -1);
    for (int i = 2; i <= n-1; i++) {
        if (c[i] > c[i-1] || c[i] > c[i+1]) {
            simu(i, 1);
            simu(i, -1);
        }
    }
    sort(z.begin(), z.end());
    if (z[0] == z[z.size()-1]) {
        cout << z[0] << "\n";
    } else {
        cout << -1 << "\n";
    }
}