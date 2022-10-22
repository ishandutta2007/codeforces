#include <bits/stdc++.h>

using namespace std;
const int INF = 100000007;

struct node{
    int sm;
    int la;
    node() : node(INF, -INF) {}
    node(int _s, int _l) : sm(_s), la(_l) {}
};

int sum[200002];
node tree[800002];

node calc(node x, node y){
    node ret;
    ret.sm = min(x.sm, y.sm);
    ret.la = max(x.la, y.la);
    return ret;
}

void init(int i, int l, int r){
    if(l == r) { tree[i] = node(sum[l], sum[l]); return; }
    int m = (l + r)/2;
    init(i*2, l, m); init(i*2+1, m+1, r);
    tree[i] = calc(tree[i*2], tree[i*2+1]);
}

node query(int i, int l, int r, int s, int e){
    if(e < s) return node(0, 0);
    if(e < l || r < s) return node(INF, -INF);
    if(s <= l && r <= e) return tree[i];
    int m = (l + r)/2;
    return calc(query(i*2, l, m, s, e), query(i*2+1, m+1, r, s, e));
}

int main()
{
    int t;
    scanf("%d", &t);
    sum[0] = 0;
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        string s;
        cin >> s;

        for(int i=0;i<n;i++){
            if(s[i] == '-') sum[i+1] = -1;
            else sum[i+1] = 1;
            sum[i+1] += sum[i];
        }

        init(1, 1, n);

        for(int i=1;i<=m;i++){
            int l, r;
            scanf("%d %d", &l, &r);
            node ret1, ret2;
            int dist = sum[l-1] - sum[r];

            if(l == 1) ret1 = node(0, 0);
            else{
                ret1 = query(1, 1, n, 1, l-1);
            }

            if(r == n) ret2 = node(0, 0);
            else{
                ret2 = query(1, 1, n, r+1, n);
                ret2.sm += dist;
                ret2.la += dist;
            }

            node ans = calc(ret1, ret2);
            ans = calc(ans, node(0, 0));

            printf("%d\n", ans.la - ans.sm + 1);
        }
    }
}