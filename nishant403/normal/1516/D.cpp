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

const int N = 1e5 + 10;

vector<int> decomp[N];

void pre()
{
    for(int i=2;i<N;i++)
    {
        if(decomp[i].empty())
            for(int j=i;j<N;j+=i) decomp[j].pb(i);
    }
}

int loc[N];
int nex[N];

const int LG = 18;
int sp[LG][N];

void solve()
{
   int n,q;
   cin >> n >> q;
    
   int a[n];
   f(i,n) cin >> a[i];
   f(i,N) loc[i] = n; 
    
   for(int i=n-1;i>=0;i--)
   {
       nex[i] = n;
       
       for(auto x : decomp[a[i]]) 
           nex[i] = min(nex[i] , loc[x]);
       
       if(i != n-1) 
           nex[i] = min(nex[i] , nex[i+1]);
       
       for(auto x : decomp[a[i]])
           loc[x] = i;
   }
    
   nex[n] = n; 
   f(i,n+1) sp[0][i] = nex[i];
   
   for(int i=1;i<LG;i++)
     for(int j=0;j<=n;j++)
       sp[i][j] = sp[i-1][sp[i-1][j]]; 
    
   int l,r; 
    
   f(i,q)
   {
       cin >> l >> r;
       l--,r--;
       
       int res = 1;
       
       for(int i=LG-1;i>=0;i--)
       {
           if(sp[i][l] <= r)
           {
               res += (1LL<<i);
               l = sp[i][l];
           }
       }
       
       cout << res <<'\n';
   }
}

signed main()
{
    pre();
    fast;
    solve();
}