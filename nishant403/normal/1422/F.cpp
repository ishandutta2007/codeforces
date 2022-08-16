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

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e5 + 10;
const int M = 2e5 + 10;

vector<pii> fcts[M];
vector<int> lprime(M,-1);

void pre()
{
   lprime[0] = lprime[1] = 0;
    
   for(int i=2;i<M;i++)
      if(lprime[i] == -1)
        for(int j=i*i;j<M;j+=i) lprime[j] = i;
       
   for(int i=2;i<M;i++)
   {
       if(lprime[i] == -1) fcts[i].pb({i,1});
       else
       {
           int temp = i;
           int cnt = 0;
           
           while(temp % lprime[i] == 0)
           {
               temp/=lprime[i];
               cnt++;
           }
           
           fcts[i] = fcts[temp];
           fcts[i].pb({lprime[i],cnt});
       }
   }
}

int n;
int a[N];

const int SZ = (N*20*10);

//persistence seg_tree
int L[SZ],R[SZ],seg[SZ];
int root[N];
int cnt = 0;

int build(int node,int l,int r)
{
    int nd = cnt++;
    seg[nd] = 1;
    
    if(l != r)
    {
    int mid = (l + r)/2;
    
    L[nd] = build(node*2+1,l,mid);
    R[nd] = build(node*2+2,mid+1,r);
    }
    
    return nd;
} 

int update(int node,int ss,int se,int id,int val)
{
    int nd = cnt++;
    
    if(ss == se)
    {
        seg[nd] = (seg[node]*val)%MOD;
        return nd;
    }
    
    int mid = (ss + se)/2;
    
    L[nd] = L[node];
    R[nd] = R[node];
    
    if(id <= mid) L[nd] = update(L[node],ss,mid,id,val);
    else R[nd] = update(R[node],mid+1,se,id,val);
    
    seg[nd] = (seg[L[nd]]*seg[R[nd]])%MOD;
    
    return nd;
}

int query(int node,int ss,int se,int l,int r)
{
    if(ss > r || se < l) return 1;
    
    if(l <= ss && se <= r) return seg[node];
    
    int mid = (ss + se)/2;
    
    return (query(L[node],ss,mid,l,r)*query(R[node],mid+1,se,l,r))%MOD;
} 

vector<pair<int,pii> > seq[M];
//index , net_power, applied_power

signed main()
{
    fast;
    
    pre();
    
    cin >> n;
    
    for(int i=1;i<=n;i++) cin >> a[i];
    
    root[0] = build(0,1,n);
    
    for(int i=1;i<=n;i++)
    {
     root[i] = update(root[i-1],1,n,i,a[i]);
        
        for(auto x : fcts[a[i]])
        {
            while(!seq[x.F].empty() && seq[x.F].back().S.F <= x.S)
            {
                int rm = mod_pow(x.F,seq[x.F].back().S.S);
                root[i] = update(root[i],1,n,seq[x.F].back().F,mod_pow(rm,MOD-2));
                seq[x.F].pop_back();
            }
            
            if(!seq[x.F].empty())
            {
                int reduce = -(seq[x.F].back().S.F - x.S - seq[x.F].back().S.S);
                seq[x.F].back().S.S -= reduce; 
                int val = mod_pow(x.F,reduce);    
                root[i] = update(root[i],1,n,seq[x.F].back().F,mod_pow(val,MOD-2));
            }
            
            seq[x.F].pb({i,{x.S,x.S}});
        }
    }
    
    int q,l,r,ans = 0;
    
    cin >> q;
    
    while(q--)
    {
        cin >> l >> r;
        
        l = ((l + ans)%n) + 1;
        r = ((r + ans)%n) + 1;
        
        if(l > r) swap(l,r);
        
        ans = query(root[r],1,n,l,r);
        
        cout << ans << '\n';
    }
}