#include <bits/stdc++.h>
#define int long long
const int INF = 1e18;
using namespace std;
vector<vector<int> > adj;
int S[200005];
int E[200005], INV[200200];
bool vis[200005];
int cnt3 = 0;
int par[200005];
void dfs(int c, int p) {
    par[c] = p;
    S[c] = cnt3;
    INV[cnt3] = c;
    cnt3++;
    for(int n : adj[c]) {
        if(n==p) continue;
        dfs(n, c);
    }
    E[c] = cnt3;
}
struct SegTree {
    struct Node {
        int a, p, cnt;
        Node(int n1, int n2, int n3) : a(n1),p(n2),cnt(n3) {}
        Node() : a(-INF),p(0),cnt(-1) {}
    };
    vector<Node> seg;
    int MAX;
    SegTree(int N) {
        int i;
        for(i=1;i<2*N;i*=2) {}
        seg.resize(i);
        MAX = i;
    }
    Node f(Node x, Node y) {
        if(x.a+x.p>y.a+y.p) return Node(x.a+x.p,0,x.cnt);
        else return Node(y.a+y.p,0,y.cnt);
    }
    void cons() {
        for(int i = MAX/2-1;i>0;i--) {
            seg[i] = f(seg[2*i],seg[2*i+1]);
        }
    }
    void prop(int n, int ns, int ne) {
        if(seg[n].p == 0) return;
        if(n < MAX/2) {
            seg[2*n].p += seg[n].p;
            seg[2*n+1].p += seg[n].p;
        }
        seg[n].a += seg[n].p;
        seg[n].p = 0;
    }
    void propall(int n) {
        if(n==0) return;
        propall(n/2);
        prop(n,1,1);
    }
    void add(int s, int e, int a, int n, int ns, int ne) {
        prop(n, ns, ne);
        if(e<=ns||ne<=s) return;
        if(s<=ns&&ne<=e) {
            seg[n].p += a;
            return;
        }
        int mid = (ns + ne) / 2;
        add(s,e,a,2*n,ns,mid);
        add(s,e,a,2*n+1,mid,ne);
        if(n<MAX/2) {
            seg[n] = f(seg[2*n],seg[2*n+1]);
        }
    }
    void add(int s, int e, int a) {
        add(s, e, a, 1, 0, MAX/2);
    }
    Node sum(int s, int e, int n, int ns, int ne) {
        prop(n, ns, ne);
        if(e<=ns||ne<=s) return Node();
        if(s<=ns&&ne<=e) return seg[n];
        int mid = (ns + ne) / 2;
        return f(sum(s,e,2*n,ns,mid),sum(s,e,2*n+1,mid,ne));
    }
};
bool vis2[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, k;
    cin >> N >> k;
    int i, j;
    int a, b;
    adj.resize(N);
    for(i=0;i<N-1;i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    SegTree tree(N+5);
    int MAX = tree.MAX;
    for(i=0;i<N;i++) {
        tree.seg[i+MAX/2].a = 0;
        tree.seg[i+MAX/2].p = 0;
        tree.seg[i+MAX/2].cnt = i;
    }
    tree.cons();
    for(i=0;i<N;i++) {
        tree.add(S[i],E[i],1);
    }
    int W = 0, B = N;
    int ans = -(N/2)*(N-N/2);
    for(i=1;i<=k;i++) {
        int m = tree.sum(0, MAX/2,1,0,MAX/2).cnt;
        int n = tree.sum(0,MAX/2,1,0,MAX/2).a;
        tree.add(m,m+1,-2*N);
        vis2[m] = true;
        B -= n;
        W += n-1;
        //cout << m << ' ' << n << ' ' << W*(i-B) << '\n';
        int wor = W * (i - B);
        if(B >= N / 2) {
            wor = min(wor, (N - N / 2 - i) * (i - N / 2));
        }
        ans = max(ans, wor);
        int c3 = INV[m];
        while(c3 != -1 && !vis[c3]) {

            vis[c3] = true;
            tree.add(S[c3],E[c3],-1);
            c3 = par[c3];
        }
    }
    cout << ans;
}