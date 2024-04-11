#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int L[1005];
int R[1005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i;
        for(i=0;i<N;i++) cin >> L[i] >> R[i];
        int j;
        for(i=0;i<N;i++) {
            cout << L[i] << ' ' << R[i] << ' ';
            if(L[i]==R[i]) {
                cout << L[i] << '\n';
                continue;
            }
            int ma = -INF;
            int mi = INF;
            for(j=0;j<N;j++) {
                if(L[j]==L[i] && R[j] < R[i]) {
                    ma = max(ma, R[j]+1);
                    //cout << R[j]+1 << '\n';
                    //break;
                }
                if(R[j]==R[i]&&L[j] > L[i]) {
                    mi = min(mi, L[j]-1);
                    //cout << L[j]-1 << '\n';
                    //break;
                }
            }
            if(ma != -INF) cout << ma << '\n';
            else cout << mi << '\n';
        }
    }
}