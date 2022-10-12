#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;

struct Tree {
    int lazy[N << 2];

    void propagate(int node) {
        if (lazy[node] == -1) return;
        
        for (int i=1; i<=2; i++)
            lazy[2*node+i] = lazy[node];
            
        lazy[node] = -1;
    }
    
    void update(int node, int l, int r, int a, int b, int val) {
        if (l > b || r < a) return;
        if (l >= a && r <= b) {
            lazy[node] = val;
            return;
        }
        
        propagate(node);
        
        int mid = l + r >> 1;
        
        update(node*2 + 1, l, mid, a, b, val);
        update(node*2 + 2, mid+1, r, a, b, val);
        return;
    }
    
    int query(int node, int l, int r, int x) {
        if (l > x || r < x) return -1;
        if (l == x && r == x) return lazy[node];
        
        propagate(node);
        
        int mid = l + r >> 1;
        return max(query(node*2+1, l, mid, x), query(node*2 + 2, mid+1, r, x));
    }
} L, R;

struct BIT {
    LL a[N];
    
    void update(int x, int val) {        
        for (int i=++x; i<=N; i+=i&-i) a[i] += val;        
    }
    
    LL query(int x) {
        LL ret = 0;
        for (int i=++x; i; i-=i&-i) ret += a[i];
        return ret;
    }
} S;

int a[N];
multiset<LL> s;

int main() {
    int n;
    scanf ("%d", &n);
    
    LL sum = 0;
    for (int i=0; i<n; i++) {
        scanf ("%d", a + i);
        L.update(0, 0, n-1, i, i, 0);
        R.update(0, 0, n-1, i, i, n-1);
        S.update(i, a[i]);
        sum += a[i];
    }
    
    s.insert(sum);
    
    int x;
    for (int i=0; i<n; i++) {
        scanf ("%d", &x);
        x--;
        
        int l = L.query(0, 0, n-1, x);
        int r = R.query(0, 0, n-1, x);
        
        // cout << l << " " << r << endl;
        
        R.update(0, 0, n-1, l, x-1, x-1);        
        L.update(0, 0, n-1, x+1, r, x+1);
        
        s.erase(s.find(S.query(r) - S.query(l-1)));
        
        S.update(x, -a[i]);
        s.insert(S.query(x-1) - S.query(l-1));
        s.insert(S.query(r) - S.query(x));

        printf ("%lld\n", *s.rbegin());
    }
    return 0;
}