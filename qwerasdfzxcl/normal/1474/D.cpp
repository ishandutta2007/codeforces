#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200];
ll val[200200];
ll tree[400400][2], lazy[400400][2];

ll init(int i, int l, int r, int idx){
    lazy[i][idx]=0;
    if (l==r){
        tree[i][idx]=val[l*2+idx];
        return tree[i][idx];
    }
    return tree[i][idx]=min(init(i*2, l, (l+r)/2, idx), init(i*2+1,(l+r)/2+1, r, idx));
}

void propagate(int i, int l, int r, int idx){
    tree[i][idx] += lazy[i][idx];
    if (l!=r){
        lazy[i*2][idx] += lazy[i][idx];
        lazy[i*2+1][idx] += lazy[i][idx];
    }
    lazy[i][idx]=0;
}

void update(int i, int l, int r, int s, int e, int p, int idx){
    propagate(i, l, r, idx);
    if (r<s || e<l) return;
    if (s<=l && r<=e){
        lazy[i][idx] += p; propagate(i, l, r, idx);
        return;
    }
    int m=(l+r)/2;
    update(i*2, l, m, s, e, p, idx), update(i*2+1, m+1, r, s, e, p, idx);
    tree[i][idx]=min(tree[i*2][idx], tree[i*2+1][idx]);
}

ll query(int i, int l, int r, int s, int e, int idx){
    propagate(i, l, r, idx);
    if (r<s || e<l) return (ll)1e18;
    if (s<=l && r<=e) return tree[i][idx];
    int m=(l+r)/2;
    return min(query(i*2, l, m, s, e, idx), query(i*2+1, m+1, r, s, e, idx));
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    ll tval=0;
    for (int i=0;i<n;i++){
        tval=a[i]-tval;
        val[i]=tval;
    }
    init(1, 0, (n-1)/2, 0);
    init(1, 0, (n-2)/2, 1);
    if (query(1, 0, (n-1)/2, (n-1)/2, (n-1)/2, (n-1)&1)==0){
        if ((n-1)&1){
            if (query(1, 0, (n-2)/2, 0, (n-2)/2-1, 1)>=0 && query(1, 0, (n-1)/2, 0, (n-1)/2, 0)>=0){
                printf("YES\n");
                return;
            }
        }
        else{
            if (query(1, 0, (n-2)/2, 0, (n-2)/2, 1)>=0 && query(1, 0, (n-1)/2, 0, (n-1)/2-1, 0)>=0){
                printf("YES\n");
                return;
            }
        }
    }
    //printf("%lld %lld\n", query(1, 0, n-1, 0, n-2), query(1, 0, n-1, n-1, n-1));

    for (int i=n-2;i>=0;i--){
        if (i&1){
            update(1, 0, (n-2)/2, i/2, i/2, a[i+1]-a[i], 1);
            update(1, 0, (n-1)/2, (i+1)/2, (n-1)/2, (ll)2*((ll)a[i]-a[i+1]), 0);
            update(1, 0, (n-2)/2, (i+2)/2, (n-2)/2, (ll)2*((ll)a[i+1]-a[i]), 1);
        }
        else{
            update(1, 0, (n-1)/2, i/2, i/2, a[i+1]-a[i], 0);
            update(1, 0, (n-2)/2, (i+1)/2, (n-2)/2, (ll)2*((ll)a[i]-a[i+1]), 1);
            update(1, 0, (n-1)/2, (i+2)/2, (n-1)/2, (ll)2*((ll)a[i+1]-a[i]), 0);
        }
        //printf("%d %lld %lld\n", i, query(1, 0, n-1, 0, n-2), query(1, 0, n-1, n-1, n-1));
        if (query(1, 0, (n-1)/2, (n-1)/2, (n-1)/2, (n-1)&1)==0){
            if ((n-1)&1){
                if (query(1, 0, (n-2)/2, 0, (n-2)/2-1, 1)>=0 && query(1, 0, (n-1)/2, 0, (n-1)/2, 0)>=0){
                    printf("YES\n");
                    return;
                }
            }
            else{
                if (query(1, 0, (n-2)/2, 0, (n-2)/2, 1)>=0 && query(1, 0, (n-1)/2, 0, (n-1)/2-1, 0)>=0){
                    printf("YES\n");
                    return;
                }
            }
        }
        if (i&1){
            update(1, 0, (n-2)/2, i/2, i/2, a[i]-a[i+1], 1);
            update(1, 0, (n-1)/2, (i+1)/2, (n-1)/2, (ll)2*((ll)a[i+1]-a[i]), 0);
            update(1, 0, (n-2)/2, (i+2)/2, (n-2)/2, (ll)2*((ll)a[i]-a[i+1]), 1);
        }
        else{
            update(1, 0, (n-1)/2, i/2, i/2, a[i]-a[i+1], 0);
            update(1, 0, (n-2)/2, (i+1)/2, (n-2)/2, (ll)2*((ll)a[i+1]-a[i]), 1);
            update(1, 0, (n-1)/2, (i+2)/2, (n-1)/2, (ll)2*((ll)a[i]-a[i+1]), 0);
        }
        //printf("%d %lld %lld\n", i, query(1, 0, n-1, 0, n-2), query(1, 0, n-1, n-1, n-1));
    }
    printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}