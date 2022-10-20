#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
string s;
int combine(int x, int y, char z){
    if (z=='?') return x+y;
    if (z=='0') return x;
    return y;
}

int k;
int calc(int x){
    int cur = 0, i=0;
    for (;i<k;i++){
        cur += (1<<i);
        if (cur>=x) break;
    }
    int ret = (1<<k)-cur;
    ret += x-(1<<i);
    return ret;
}
struct Seg{
    int tree[1001000], sz;
    void init(int n){
        sz = n;
        for (int i=sz;i<sz*2;i++) tree[i] = 1;
        for (int i=sz-1;i>0;i--) tree[i] = combine(tree[i<<1], tree[i<<1|1], s[calc(i)-1]);
    }
    void update(int x){
        for (;x;x>>=1) tree[x] = combine(tree[x<<1], tree[x<<1|1], s[calc(x)-1]);
    }
}tree;

int INV[500500];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> k >> s;
    for (int i=1;i<(1<<k);i++) INV[calc(i)] = i;
    n = (1<<k);
    tree.init(n);
    int q;
    cin >> q;
    while(q--){
        int a;
        char b;
        cin >> a >> b;
        s[a-1] = b;
        tree.update(INV[a]);
        cout << tree.tree[1] << '\n';
    }
    return 0;
}