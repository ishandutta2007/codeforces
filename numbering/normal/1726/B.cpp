#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        int N, M;
        cin >> N >> M;
        if(M<N) cout << "No\n";
        else if(N % 2 == 1) {
            cout << "Yes\n";
            for(i=0;i<N-1;i++) cout << "1 ";
            cout << M - (N-1) << '\n';
        }
        else {
            if(M%2==1) cout << "No\n";
            else {
                cout << "Yes\n";
                for(i=0;i<N-2;i++) cout << "1 ";
                int c = (M - (N-2)) / 2;
                cout << c << ' ' << c << '\n';
            }
        }
    }
}