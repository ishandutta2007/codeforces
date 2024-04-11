#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        if(m > (n+1)/2) {
            cout << -1 << endl;
        }
        else {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j && i%2 == 0 && i < m*2) cout << 'R';
                    else cout << '.';
                }
                cout << endl;
            }
        }
    }
    return 0;
}