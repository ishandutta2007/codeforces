#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int a[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int ok = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i-1]) ok = 1;
        }
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}