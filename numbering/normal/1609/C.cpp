#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
bool isPrime[1000005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int M = 1e6 + 3;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for(int i=2;i<=M;i++) {
        if(isPrime[i]) {
            for(int j=i*i;j<=M;j+=i) isPrime[j] = false;
        }
    }
    while(t--) {
        int N, e;
        cin >> N >> e;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=0;i<N;i++) {
            if(A[i]==1) A[i] = 1;
            else if(isPrime[A[i]]) A[i] = 0;
            else A[i] = -1;
        }
        vector<bool> vis;
        vis.resize(N);
        int ans = 0;
        for(i=0;i<N;i++) {
            if(vis[i]) continue;
            vector<int> B;
            for(j=i;j<N;j+=e) {
                vis[j] = true;
                B.push_back(A[j]);
            }
            vector<int> B2;
            int k;
            for(j=0;j<B.size();j++) {
                if(B[j] != 1) B2.push_back(B[j]);
                else {
                    int k = j;
                    while(j+1<B.size()&&B[j+1]==1) j++;
                    B2.push_back(j-k+1);
                }
            }
            for(j=0;j<B2.size();j++) {
                int k1, k2;
                if(j==0||B2[j-1]<=0) k1 = 0;
                else k1 = B2[j-1];
                if(j==B2.size()-1||B2[j+1]<=0) k2 = 0;
                else k2 = B2[j+1];
                if(B2[j] == 0) {
                    ans += (k1 + 1) * (k2 + 1) - 1;
                }
                //cout << k1 << ' ' << k2 << '\n';
            }
        }
        cout << ans << '\n';
    }
}