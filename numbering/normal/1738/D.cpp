#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
int B[100005];
int C[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=0;i<N;i++) A[i]--;
        for(i=0;i<N;i++) B[i] = 0;
        for(i=0;i<N;i++) {
            if(A[i]!=-1&&A[i]!=N) {
                B[A[i]]++;
            }
        }
        vector<vector<int>> adj;
        adj.resize(N);
        for(i=0;i<N;i++) {
            if(A[i]!=-1&&A[i]!=N) {
                adj[A[i]].push_back(i);
            }
        }
        vector<int> V;
        vector<int> V2;
        int val = -1;
        int ma = -1, mi = N;
        for(i=0;i<N;i++) {
            if(A[i]==-1||A[i]==N) {
                ma = max(ma, i);
                mi = min(mi, i);
                if(B[i]==0) V.push_back(i);
                else val = i;
            }
        }
        if(val!=-1) V.push_back(val);
        int rev = 1;
        while(val!=-1) {
            int v2 = -1;
            for(int n : adj[val]) {
                if(B[n]==0) V.push_back(n);
                else v2 = n;
                if(rev==0) {
                    ma = max(ma, n);
                    mi = min(mi, n);
                }
            }
            if(v2!=-1) V.push_back(v2);
            val = v2;
            rev ^= 1;
        }
        int k = -1;
        bool Allzero = true;
        bool AllN = true;
        for(i=0;i<N;i++) {
            if(A[i]!=-1) Allzero = false;
            if(A[i]!=N) AllN = false;
        }
        if(Allzero) k = -1;
        else if(AllN) k = N;
        else {
            if(ma==N-1) k = mi - 1;
            else k = ma;
        }
        assert(V.size()==N);
        k = min(k, N-1);
        k = max(k, (int)-1);
        cout << k + 1 << '\n';
        for(i=0;i<V.size();i++) cout << V[i]+1 << ' ';
        cout << '\n';
        vector<int> C;
        C.resize(N);
        int r1 = N, r2 = -1;
        for(i=0;i<N;i++) {
            if(V[i]<=k) C[V[i]] = r1;
            else C[V[i]] = r2;
            if(V[i]<=k) r2 = V[i];
            else r1 = V[i];
            //assert(C[i]==A[i]);
        }
        for(i=0;i<N;i++) assert(C[i]==A[i]);
    }
}