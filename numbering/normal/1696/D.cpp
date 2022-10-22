#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
typedef pair<int,int> P;
struct SegTree {
    vector<int> seg;
    int MAX;
    void init(int N) {
        seg.clear();
        int i;
        for(i=1;i<2*N;i*=2) {}
        seg.resize(i);
        MAX = i;
        for(i=0;i<MAX;i++) seg[i] = -INF;
    }
    void cons() {
        for(int i=MAX/2-1;i>=1;i--) {
            seg[i] = max(seg[2*i],seg[2*i+1]);
        }
    }
    int sum(int s, int e, int n, int ns, int ne) {
        if(e<=ns||ne<=s) return -INF;
        if(s<=ns&&ne<=e) return seg[n];
        int mid = ns + ne >> 1;
        return max(sum(s,e,2*n,ns,mid),sum(s,e,2*n+1,mid,ne));
    }
    int sum(int s, int e) {
        return sum(s,e,1,0,MAX/2);
    }
};
struct SegTree2 {
    vector<int> seg;
    int MAX;
    void init(int N) {
        seg.clear();
        int i;
        for(i=1;i<2*N;i*=2) {}
        seg.resize(i);
        MAX = i;
        for(i=0;i<MAX;i++) seg[i] = INF;
    }
    void cons() {
        for(int i=MAX/2-1;i>=1;i--) {
            seg[i] = min(seg[2*i],seg[2*i+1]);
        }
    }
    int sum(int s, int e, int n, int ns, int ne) {
        if(e<=ns||ne<=s) return INF;
        if(s<=ns&&ne<=e) return seg[n];
        int mid = ns + ne >> 1;
        return min(sum(s,e,2*n,ns,mid),sum(s,e,2*n+1,mid,ne));
    }
    int sum(int s, int e) {
        return sum(s,e,1,0,MAX/2);
    }
};
int A[500005];
int B[500005];
int C[500005];
int D[500005];
SegTree tree;
SegTree2 tree2;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        clock_t st = clock();
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        /*for(i=0;i<N;i++) {
            if(i%2==0) {
                A[i] = N/2 + i/2 ;
            }
            else {
                A[i] = N/2 - 1 - i/2;
            }
        }*/
        //random_shuffle(A, A+N);
        for(i=0;i<N;i++) A[i]--;
        for(i=0;i<N;i++) B[i] = 0;
        for(i=0;i<N;i++) B[A[i]] = i;
        for(i=0;i<N;i++) C[i] = D[i] = -1;
        stack<P> S1;
        for(i=0;i<N;i++) {
            while(!S1.empty()&&S1.top().first>A[i]) {
                C[S1.top().second] = i;
                S1.pop();
            }
            S1.push(P(A[i],i));
        }
        while(!S1.empty()) {
            C[S1.top().second] = N;
            S1.pop();
        }
        stack<P> S2;
        for(i=0;i<N;i++) {
            while(!S2.empty()&&S2.top().first<A[i]) {
                D[S2.top().second] = i;
                S2.pop();
            }
            S2.push(P(A[i],i));
        }
        while(!S2.empty()) {
            D[S2.top().second] = N;
            S2.pop();
        }
        tree.init(N+5);
        tree2.init(N+5);
        int MAX = tree.MAX;
        for(i=0;i<N;i++) {
            tree.seg[i+MAX/2] = tree2.seg[i+MAX/2] = A[i];
        }
        tree.cons();
        tree2.cons();
        int id = 0;
        int ans = 0;
        int prv = -1;
        while(id<N-1) {
            prv = id;
            if(A[id]<A[id+1]) {
                //cout << "min case : " << id << ' ' << s << '\n';
                int ma = tree.sum(id, C[id]+1);
                id = B[ma];
                ans++;
            }
            else {
                //cout << "max case : " << id << ' ' << s << '\n';
                int mi = tree2.sum(id, D[id]+1);
                id = B[mi];
                ans++;
            }
            assert(id!=-1);
            assert(prv < id);
        }
        cout << ans << '\n';
        //cout << clock() - st << "ms";
    }
}