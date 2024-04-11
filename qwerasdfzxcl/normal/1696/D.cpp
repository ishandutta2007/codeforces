#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Node1{
    int mn, idx;
    Node1(){}
    Node1(int _mn, int _idx): mn(_mn), idx(_idx) {}
    Node1 operator + (const Node1 &N) const{
        if (mn < N.mn) return *this;
        return N;
    }
};
struct Node2{
    int mx, idx;
    Node2(){}
    Node2(int _mx, int _idx): mx(_mx), idx(_idx) {}
    Node2 operator + (const Node2 &N) const{
        if (mx > N.mx) return *this;
        return N;
    }
};
struct Seg1{
    Node1 tree[1001000];
    int sz;
    void init(int n, int *a){
        sz = n;
        for (int i=sz;i<sz*2;i++) tree[i] = Node1(a[i-sz], i-sz);
        for (int i=sz-1;i;i--) tree[i] = tree[i<<1] + tree[i<<1|1];
    }
    Node1 query(int l, int r){
        r++;
        Node1 ret = Node1(1e9, 0);
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret = ret + tree[l++];
            if (r&1) ret = ret + tree[--r];
        }
        return ret;
    }
}tree1;
struct Seg2{
    Node2 tree[1001000];
    int sz;
    void init(int n, int *a){
        sz = n;
        for (int i=sz;i<sz*2;i++) tree[i] = Node2(a[i-sz], i-sz);
        for (int i=sz-1;i;i--) tree[i] = tree[i<<1] + tree[i<<1|1];
    }
    Node2 query(int l, int r){
        r++;
        Node2 ret = Node2(-1e9, 0);
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret = ret + tree[l++];
            if (r&1) ret = ret + tree[--r];
        }
        return ret;
    }
}tree2;

int calcmn(int l, int r, bool left);
int calcmx(int l, int r, bool left);

int calcmn(int l, int r, bool left){
    if (l==r) return 0;
    int mn = tree1.query(l, r).idx;

    if (l==1) return calcmx(l, mn, left) + 1;
    return calcmx(mn, r, left) + 1;
}

int calcmx(int l, int r, bool left){
    if (l==r) return 0;
    int mx = tree2.query(l, r).idx;

    if (left) return calcmn(l, mx, left) + 1;
    return calcmn(mx, r, left) + 1;
}

int a[500500];
void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    tree1.init(n+1, a);
    tree2.init(n+1, a);

    int mn = tree1.query(1, n).idx;
    printf("%d\n", calcmx(1, mn, 1) + calcmx(mn, n, 0));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}