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

const int N = 1e5 + 10;
const int inf = 1e9 + 10;

int seg[2*N];
int n,k;

int query(int l,int r)
{
    l+=n;
    r+=n+1;
    
    int res = inf;
    
    for(;l<r;l>>=1,r>>=1)
    {
        if(l&1) res = min(res,seg[l++]);
        if(r&1) res = min(res,seg[--r]);
    }
    
    return res;
}

struct node
{
    int l,r,mn,lazy;
    node*L,*R;
    
    void init(int ll,int rr,int val)
    {
        mn = val;
        l = ll;
        r = rr;
        lazy = inf;
        L = R = NULL;
    }
};

node* root;

int go(int l,int r)
{
    if((r-l+1) >= n) return seg[1];
    
    l%=n;  r%=n;
    
    if(l <= r) return query(l,r);
    return min(query(l,n-1),query(0,r));
}

void upd(node* nd,int l,int r,int x)
{
    if(nd->lazy != inf) nd->mn = nd->lazy;
    
    int ss = nd->l; 
    int se = nd->r;
       
    if(ss > r || se < l) return;
    
    if(l <= ss && se <= r)  
    {
        nd->mn = nd->lazy = x;
        return;
    }
    
    int mid = (ss + se)/2;
    
    if(nd->L == NULL)
    {
        nd->L = new node();
        nd->L->init(ss,mid,go(ss,mid));
    }
    
    if(nd->R == NULL)
    {
        nd->R = new node();
        nd->R->init(mid+1,se,go(mid+1,se));
    }
    
    if(nd->lazy != inf)
    {
    nd->L->lazy = nd->lazy;
    nd->R->lazy = nd->lazy;
    nd->lazy = inf;
    }
    
    upd(nd->L,l,r,x);  
    upd(nd->R,l,r,x);
   
    nd->mn = min(nd->L->mn,nd->R->mn);
}

int query2(node* nd,int l,int r)
{
    if(nd->lazy != inf) nd->mn = nd->lazy;
    
    int ss = nd->l; int se = nd->r;
    
    if(ss > r || se < l) return inf;
    
    if(l <= ss && se <= r) return nd->mn;
    
    int mid = (ss + se)/2;
    
    if(nd->L == NULL)
    {
        nd->L = new node();
        nd->L->init(ss,mid,go(ss,mid));
    }
    
    if(nd->R == NULL)
    {
        nd->R = new node();
        nd->R->init(mid+1,se,go(mid+1,se));
    }
    
    if(nd->lazy != inf)
    {
    nd->L->lazy = nd->lazy;
    nd->R->lazy = nd->lazy;
    nd->lazy = inf;
    }
    
    return min(query2(nd->L,l,r),query2(nd->R,l,r));
}

signed main()
{
    fast;
    
    cin >> n >> k;
    
    f(i,n) cin >> seg[i+n];
    
    for(int i=n-1;i>=1;i--)
        seg[i] = min(seg[i<<1],seg[i<<1^1]);
    
    root = new node();
    root->init(0,(n*k)-1,seg[1]);
    
    int q;
    cin >> q;
    
    int t,l,r,x;
    
    while(q--)
    {
        cin >> t >> l >> r;
        l--; r--;
        
        if(t == 1)
        {
            cin >> x;
            upd(root,l,r,x);
        }
        else cout << query2(root,l,r) << '\n';
    }
}