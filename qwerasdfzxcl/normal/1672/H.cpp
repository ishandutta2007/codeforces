#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Node{
    int c0, c1, l, r;
    Node(){}
    Node(int _c0, int _c1, int _l, int _r): c0(_c0), c1(_c1), l(_l), r(_r) {}
    Node operator+(const Node &N) const{
        if (r==-1) return N;
        if (N.r==-1) return *this;
        Node ret = Node(c0 + N.c0, c1 + N.c1, l, N.r);
        if (r==N.l){
            if (r==0) ret.c0++;
            else ret.c1++;
        }
        return ret;
    }
};
string s;
struct Seg{
    Node tree[800800];
    void init(int i, int l, int r){
        if (l==r){
            tree[i] = Node(0, 0, s[l]-'0', s[l]-'0');
            return;
        }
        int m = (l+r)>>1;
        init(i<<1, l, m); init(i<<1|1, m+1, r);
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
    Node query(int i, int l, int r, int s, int e){
        if (r<s || e<l) return Node(-1, -1, -1, -1);
        if (s<=l && r<=e) return tree[i];
        int m = (l+r)>>1;
        return query(i<<1, l, m, s, e) + query(i<<1|1, m+1, r, s, e);
    }
}tree;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q >> s;
    tree.init(1, 0, n-1);

    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        auto ans = tree.query(1, 0, n-1, l, r);
        cout << max(ans.c0, ans.c1) + 1 << '\n';
    }
    return 0;
}