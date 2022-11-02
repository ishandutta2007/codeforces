#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define st first
#define nd second

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int R = 0;
        int W = 0;
        for(int i=0;i<m;i++) {
            int r, w;
            cin >> r >> w;
            R = max(R, r);
            W = max(W, w);
        }
        if(R+W > n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for(int i=0;i<R;i++) {
                cout << "R";
            }
            for(int i=0;i<W;i++) {
                cout << "W";
            }
            for(int i=0;i<n-W-R;i++) {
                cout << "W";
            }
            cout << "\n";
        }
    }
}