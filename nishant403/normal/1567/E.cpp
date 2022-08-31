#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

const int N = 2e5 + 10;

FenwickTree go(N);

int n,q;
int a[N];
int ss[N];

set<int> ind;

void update(int x,int y)
{
    //first remove all connections
    int prv = *(--ind.upper_bound(x));
    int nxt = *ind.upper_bound(x);
    int len = nxt - prv;
        
    go.add(prv,ss[x-prv] - ss[len]);
    go.add(x,1);
    go.add(x+1,ss[nxt-x-1]);
   
    ind.insert(x);
    ind.insert(x + 1);
    
    //then add all connections
    a[x] = y;
    
    if(x > 0 && a[x-1] <= a[x])
    {
        prv = *(--ind.upper_bound(x-1));
        ind.erase(x);
        go.add(x,-1);
        go.add(prv,x-prv+1);
    }
    else prv = x;
    
    if(x < n-1 && a[x] <= a[x+1])
    {
        ind.erase(x+1);
        
        if(nxt == x + 1)
        {
            nxt = *ind.upper_bound(nxt);
        }
        
        go.add(x+1,-ss[nxt-x-1]);
        go.add(prv,ss[nxt-prv] - go.sum(prv,prv));
    }
}

int query(int l,int r)
{
    if(l > r) return 0;
    else if(*ind.upper_bound(l) > r) return ss[r-l+1];
    
    int nx = *ind.lower_bound(l);
    
    if(nx != l) return ss[nx - l] + query(nx,r);
    else 
    {
        int prv = *(--ind.upper_bound(r));
        return ss[r-prv+1] + go.sum(l,prv-1);
    }
}

void solve()
{
    cin >> n >> q;
    f(i,n) cin >> a[i];
    
    ind.insert(n);
    
    for(int i=n-1;i>=0;i--)
    {
        if(i == 0 || a[i] < a[i-1])
        {
            go.add(i,ss[*ind.begin() - i]);
            ind.insert(i);
        }
    }
    
    int t,x,y;
    
    while(q--)
    {
        cin >> t >> x >> y;
        
        if(t == 1) update(x-1,y);
        else cout << query(x-1,y-1) << '\n';
    }
}

signed main()
{
    for(int i=1;i<N;i++) ss[i] = ss[i-1] + i;
    
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}