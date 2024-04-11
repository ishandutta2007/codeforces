#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct Query{
    int first, second, idx;
}query[300300];
vector<int> D[300300];
int a[300300], pt[300300], ans[300300];
set<int> st;

struct Seg{
    int tree[600600], sz, cur;
    void init(int n){
        sz = n, cur = 0;
    }
    void update(int l, int r){
        for (l += sz, r += sz;l<r;l>>=1, r>>=1){
            if (l&1) tree[l++]++;
            if (r&1) tree[--r]++;
        }
    }
    int query(int x){
        int ret = 0;
        for (ret += tree[x+=sz];x>1;x>>=1) ret += tree[x>>1];
        return ret;
    }
    int lower_bound(int x){
        int l = 1, r = cur+1;
        while(l<r){
            int m = (l+r)>>1;
            if (query(m)>=x) l = m+1;
            else r = m;
        }
        return l-1;
    }
}tree;

bool comp(Query &x, Query &y){
    return x.second<y.second;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    tree.init(n+1);
    for (int i=1;i<=n;i++){
        scanf("%d", a+i); a[i] = i-a[i];
    }
    for (int i=0;i<q;i++){
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        query[i].first = tmp1+1;
        query[i].second = n-tmp2;
        query[i].idx =i;
    }
    sort(query, query+q, comp);
    int pt = 0;
    for (int i=1;i<=n;i++){
        if (a[i]>=0){
            int tmp = tree.lower_bound(a[i]);
            tree.update(1, tmp+1);
        }
        tree.cur++;
        if (!a[i]) tree.update(i, i+1);
        for(;pt<q;pt++){
            if (query[pt].second!=i) break;
            ans[query[pt].idx] = tree.query(query[pt].first);
        }
    }
    for (int i=0;i<q;i++) printf("%d\n", ans[i]);
    return 0;
}