#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Node{
    int a, b, c, ab, bc, abc;
    Node(){}
    Node(int _a, int _b, int _c, int _ab, int _bc, int _abc): a(_a), b(_b), c(_c), ab(_ab), bc(_bc), abc(_abc) {}
};
struct Seg{
    Node tree[400400];
    Node combine(Node l, Node r){
        Node ret = Node(l.a+r.a, l.b+r.b, l.c+r.c, 0, 0, 0);
        ret.ab = min(min(l.ab + r.b, l.a + r.ab), l.a + r.b);
        ret.bc = min(min(l.b + r.bc, l.bc + r.c), l.b + r.c);
        ret.abc = min(min(l.abc + r.c, l.a + r.abc), l.ab+r.bc);
        return ret;
    }
    void init(int i, int l, int r, string &s){
        if (l==r) {
            tree[i] = Node(0, 0, 0, 0, 0, 0);
            if (s[l]=='a') tree[i].a++;
            if (s[l]=='b') tree[i].b++;
            if (s[l]=='c') tree[i].c++;
            return;
        }
        int m = (l+r)>>1;
        init(i<<1, l, m, s);
        init(i<<1|1, m+1, r, s);
        tree[i] = combine(tree[i<<1], tree[i<<1|1]);
    }
    void update(int i, int l, int r, int x, char val){
        if (r<x || x<l) return;
        if (l==r){
            tree[i] = Node(0, 0, 0, 0, 0, 0);
            if (val=='a') tree[i].a++;
            if (val=='b') tree[i].b++;
            if (val=='c') tree[i].c++;
            return;
        }
        int m = (l+r)>>1;
        update(i<<1, l, m, x, val);
        update(i<<1|1, m+1, r, x, val);
        tree[i] = combine(tree[i<<1], tree[i<<1|1]);
    }
}tree;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, q;
    string s;
    cin >> n >> q >> s;
    tree.init(1, 0, n-1, s);

    while(q--){
        int x;
        char y;
        cin >> x >> y;
        --x;

        s[x] = y;
        tree.update(1, 0, n-1, x, y);
        cout << tree.tree[1].abc << '\n';
    }
    return 0;
}