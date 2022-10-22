#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[500005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, K;
        cin >> N ;
        if(N<=2) cout << "-1\n";
        else {
            int c2 = 2*N;
            int c1 = 1;
            while(c2%2==0) {
                c2 /= 2;
                c1 *= 2;
            }
            if(c1<c2) swap(c1,c2);
            int k = c2;
            int a = (c1-c2-1)/2;
            if(a>=0&&k>=2) cout << k << '\n';
            else cout << "-1\n";
        }
    }
}