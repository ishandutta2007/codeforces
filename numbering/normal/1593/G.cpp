#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
struct SegTree {
    struct Node {
        int st, en;
        int L;
        Node() : st(0),en(0),L(0) {}
        Node(int s1, int e1, int l1):st(s1),en(e1),L(l1){}
    };
    vector<Node> seg;
    int MAX;
    SegTree(int N) {
        int i;
        for(i=2;i<2*N;i*=2) {}
        MAX = i;
        seg.resize(i);
    }
    Node f(Node x, Node y) {
        if(x.L==0) return y;
        if(y.L==0) return x;
        if(x.en != y.st) return Node(x.st, y.en,x.L+y.L);
        if(x.L==y.L) return Node();
        if(x.L<y.L) return Node(3-x.st,y.en,y.L-x.L);
        else return Node(x.st,3-y.en,x.L-y.L);
    }
    void cons() {
        for(int i=MAX/2-1;i>=1;i--) {
            seg[i] = f(seg[2*i],seg[2*i+1]);
        }
    }
    Node sum(int s, int e, int n, int ns, int ne) {
        if(e<=ns||ne<=s) return Node();
        if(s<=ns&&ne<=e) return seg[n];
        int mid = ns+ne>>1;
        return f(sum(s,e,2*n,ns,mid),sum(s,e,2*n+1,mid,ne));
    }
    int sum(int s, int e) {
        Node k = sum(s,e,1,0,MAX/2);
        return k.L/2;
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        int Q;
        int N;
        cin >> s >> Q;
        N = s.length();
        SegTree tree(N+5);
        int MAX = tree.MAX;
        int i;
        for(i=0;i<N;i++) {
            tree.seg[i+MAX/2].st = (s[i] == '('||s[i]==')')?1:2;
            tree.seg[i+MAX/2].en = tree.seg[i+MAX/2].st;
            tree.seg[i+MAX/2].L=1;
        }
        tree.cons();
        int l, r;
        for(i=0;i<Q;i++) {
            cin >> l >> r;
            cout << tree.sum(l-1,r)<<'\n';
        }
    }
}