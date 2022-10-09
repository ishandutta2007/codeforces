// By Qingyu
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k = 0;
        while(k < n && a[k] == 1) {
            k++;
        }
        cout << ((k == n) ^ (k % 2) ? "Second" : "First") << '\n';
    }
}