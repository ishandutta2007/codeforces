#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
int B[100005];
bool vis[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        int N;
        cin >> N;
        for(i=0;i<N;i++) {
            int a;
            cin >> a;
            A[a] = i;
        }
        for(i=0;i<N;i++) {
            int b;
            cin >> b;
            B[i] = A[b];
        }
        for(i=0;i<N;i++) vis[i] = false;
        int cnt = 0;
        for(i=0;i<N;i++) {
            if(!vis[i]) {
                int ck = 0;
                int id = i;
                while(!vis[id]) {
                    ck++;
                    vis[id] = true;
                    id = B[id];
                }
                if(ck%2==1) cnt++;
            }
        }
        int m = (N-cnt)/2;
        int ans = 0;
        for(i=1;i<=m;i++) ans -= i;
        for(i=N-m+1;i<=N;i++) ans += i;
        cout << 2*ans << '\n';
    }
}