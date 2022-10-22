#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[300005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, x;
        cin >> N >> x;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        map<int,int> M;
        for(i=0;i<N;i++) M[A[i]]++;
        int ans = 0;
        for(auto it = M.begin();it!=M.end();it++) {
            if(it->second==0) continue;
            if(M[it->first] <= M[x*it->first]) {
                M[x*it->first] -= M[it->first];
                M[it->first] = 0;
            }
            else {
                ans += M[it->first] - M[x*it->first];
                M[it->first] = M[x*it->first] = 0;
            }
        }
        cout << ans << '\n';
    }
}