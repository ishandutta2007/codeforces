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

const int N = 5e5 + 10;
int basis[N];
int cover[N];
int dsu[N];
int sz[N];
int place[N];
int cn = 0;

int find(int x)
{
    if(x == dsu[x]) return x;
    return dsu[x] = find(dsu[x]);
}

void merge(int x,int y,int g)
{
    int p = find(x);
    int q = find(y);
    
    place[p] = place[q] = g;
    
    if(p == q) return;
    
    if(sz[p] > sz[q]) swap(p,q);
    sz[q]+=sz[p];
    dsu[p] = q;
}

void insert(int id,int x,int y)
{
    int o1 = place[find(x)];
    int o2 = place[find(y)];
    
    if(o1 > o2) swap(o1,o2);
    if(o2 == 0) return;
    if(o1 == o2) return;
    
    cover[o2] = 1;
    basis[cn++] = id;
    merge(o1,o2,o1); 
    return ;
}

void solve()
{
   int n,m;
   cin >> n >> m;
     
   for(int i=0;i<=m;i++)
       dsu[i] = i,sz[i] = 1,place[i] = i;
    
   f(i,n)
   {
       int sz,x = 0,y = 0;
       cin >> sz;
       
       cin >> x;
       if(sz == 2) cin >> y;
       insert(i+1,x,y);
   }
    
   cout << mod_pow(2,cn) << ' ' << cn << '\n';
   f(i,cn) cout << basis[i] << ' ';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}