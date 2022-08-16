#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e6 + 10;
int n,k;
int a[N];

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

int pos[N];
int rr[N];

signed main()
{
    fast;
    
    cin >> n >> k;
    
    f(i,n) cin >> a[i];
    f(i,n) pos[a[i]] = i;
    
    int x;
    
    f(i,k)
    {
        cin >> x;
        rr[x] = 1;
    }
    
    FenwickTree go(n);
    f(i,n) go.add(i,1);
    
    vector<pii> rm;
    
    f(i,n) if(rr[a[i]] == 0) rm.pb({a[i],i});
    
    sort(rm.begin(),rm.end());
        
    set<int> ids;
    
    long long int res = 0;
    
    int cnt = 1;
    
    ids.insert(-1);
    ids.insert(n);
    
    for(auto x : rm)
    {
        while(cnt < x.F)
        {
            ids.insert(pos[cnt]);
            cnt++;
        }
        
        int rr = (*ids.lower_bound(x.S));
        int ll = (*(--ids.lower_bound(x.S)));
        
        ll++;
        rr--;
        
        res+=go.sum(ll,rr);
        go.add(x.S,-1);
        cnt++;
    }
    
    cout << res;
}