#include<bits/stdc++.h>
using namespace std;

int n, m;
long long tree[850002]={}, lazy[850002]={};

void propagate(int node){
    lazy[2*node+0] += lazy[node];
    tree[2*node+0] += lazy[node];
    lazy[2*node+1] += lazy[node];
    tree[2*node+1] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int l, int r, int a, int b, long long val){
    if (r < a || l > b) return;
    if (a <= l && b >= r){
        lazy[node] += val;
        tree[node] += val;
        return;
    }

    propagate(node);
    int mid = (l+r)/2;
    update(2*node+0, l, mid+0, a, b, val);
    update(2*node+1, mid+1, r, a, b, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

long long query(int node, int l, int r, int a, int b){
    if (r < a || l > b) return (long long) 1e+18;
    if (a <= l && b >= r) return tree[node];

    propagate(node);
    int mid = (l+r)/2;
    return min(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));
}
int main(){
    scanf("%d", &n);
    int tmp;
    for (int i=0; i<n; i++) {
        scanf("%d", &tmp);
        update(1, 0, n-1, i, i, tmp);
    }

    scanf("%d\n", &m);
    for (int i=0; i<m; i++){
        char c[100];
        int lf, rf, v;
        gets(c);
        if (sscanf(c, "%d %d %d", &lf, &rf, &v) == 3){
            if (lf <= rf) update(1, 0, n-1, lf, rf, v);
            else {
                update(1, 0, n-1, lf, n-1, v);
                update(1, 0, n-1, 0, rf, v);
            }
            //for (int i=0; i<n; i++) cout << query(1, 0, n-1, i, i) << " "; cout << endl;
        }
        else {
            if (lf <= rf) printf("%I64d\n", query(1, 0, n-1, lf, rf));
            else {
                printf("%I64d\n", min(query(1, 0, n-1, lf, n-1), query(1, 0, n-1, 0, rf)));
            }
        }
    }
    return 0;
}