#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
struct SegTree {
    vector<int> seg;
    int MAX;
    SegTree(int N) {
        int i;
        for(i=1;i<2*N;i*=2) {}
        seg.resize(i);
        MAX = i;
    }
    void update(int n) {
        n += MAX/2;
        n /= 2;
        while(n) {
            seg[n] = max(seg[2*n], seg[2*n+1]);
            n /= 2;
        }
    }
    void cons() {
        for(int i = MAX/2-1;i>=1;i--) {
            seg[i] = max(seg[2*i],seg[2*i+1]);
        }
    }
    void Edit(int n, int a) {
        seg[n+MAX/2] = a;
        update(n);
    }
    int sum() {
        return seg[1];
    }
};
int A[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, Q;
        cin >> N >> Q;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        vector<int> R;
        vector<vector<int>> V;
        int N2 = N;
        vector<map<int,int>> S;
        int ma = 0;
        for(i=2;i<=N2;i++) {
            if(N2%i==0) {
                R.push_back(i);
                while(N2%i==0) {
                    N2 /= i;
                }
                vector<int> V2;
                V2.resize(N/i);
                for(j=0;j<N;j++) {
                    V2[j%(N/i)] += A[j];
                }
                map<int,int> M;
                for(j=0;j<N/i;j++) {
                    M[V2[j]]++;
                }
                V.push_back(V2);
                S.push_back(M);
            }
        }
        for(i=0;i<R.size();i++) {
            int p = R[i];
            ma = max(ma, N/p * (S[i].rbegin()->first));
        }
        //cout << "init done\n";
        if(R.size()==1&&R[0]==N) {
            int sum = 0;
            for(i=0;i<N;i++) sum += A[i];
            cout << sum << '\n';
            while(Q--) {
                int p, x;
                cin >> p >> x;
                p--;
                sum += x - A[p];
                A[p] = x;
                cout << sum << '\n';
            }
            continue;
        }
        cout << ma << '\n';
        while(Q--) {
            int k, x;
            cin >> k >> x;
            k--;
            for(i=0;i<R.size();i++) {
                int p = R[i];
                if(S[i][V[i][k%(N/p)]]>1) S[i][V[i][k%(N/p)]]--;
                else S[i].erase(V[i][k%(N/p)]);
                V[i][k%(N/p)] -= A[k];
            }
            int ma = 0;
            for(i=0;i<R.size();i++) {
                int p = R[i];
                V[i][k%(N/p)] += x;
                S[i][V[i][k%(N/p)]]++;
                ma = max(ma, N/p * (S[i].rbegin()->first));
            }
            A[k] = x;
            cout << ma << '\n';
        }
    }
}