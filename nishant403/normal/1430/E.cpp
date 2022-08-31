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

const int N = 26;
vi g[N];

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

void solve()
{
   int n;
   cin >> n;
    
   string s;
   cin >> s;
    
   f(i,n) g[s[i] - 'a'].pb(i); 
   f(i,26) reverse(g[i].begin(),g[i].end()); 
    
   string t = s;
   reverse(t.begin(),t.end());
   
   FenwickTree FT(n+1);
    
   int res = 0; 
    
   f(i,n)
   {
       //find the character whose index is i
       int go = g[t[i] - 'a'].back();
       g[t[i] - 'a'].pop_back();
       
       //find index of go
       int id = go - FT.sum(0,go); 
       
       res+=id;
       
       FT.add(go,1); 
   }
    
   cout << res; 
}

signed main()
{
    fast;
    solve();
}