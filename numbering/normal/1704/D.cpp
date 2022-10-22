#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
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
        vector<vector<int>> A;
        A.resize(N);
        for(i=0;i<N;i++) {
            A[i].resize(M);
            for(j=0;j<M;j++) cin >> A[i][j];
        }
        vector<int> cnt;
        cnt.resize(N);
        map<int,int> M2;
        for(i=0;i<N;i++) {
            for(j=0;j<M;j++) cnt[i] += j*A[i][j];
            M2[cnt[i]]++;
        }
        int res = 0;
        for(auto it = M2.begin();it!=M2.end();it++) {
            if(it->second >= 2) res = it->first;
        }
        int id = -1, id2 = -1;
        for(i=0;i<N;i++) {
            if(cnt[i] != res) {
                id = i;
                id2 = res - cnt[i];
            }
        }
        cout << id+1 << ' ' << -id2 << '\n';
    }
}