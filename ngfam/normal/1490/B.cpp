#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        vector<int> a(n), b(3);
        for(int i = 0; i < n; ++i) cin >> a[i], b[a[i] % 3]++;

        int ans = 0;
        for(int j = 0; j < 2; ++j) {
            for(int i = 0; i < 3; ++i) {
                if(b[i] < n/3) {
                    int delta = n/3 - b[i];
                    b[i] += delta;
                    ans += delta;
                    b[(i + 2) % 3] -= delta;
                }
            }
        }
        

        cout << ans << endl;
    }

    return 0;
}