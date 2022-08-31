#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 5e5 + 100;

vector<int> fct[N];

void pre()
{
    for(int i=2;i<N;i++)
    {
        if(fct[i].empty())
            for(int j=i;j<N;j+=i) fct[j].pb(i);
    }
}

int ml[N];
int fre[N];
int a[N];
long long int res = 0;

void add(int num,int sn)
{   
    int sz = fct[num].size();
    
    f(j,(1<<sz))
    {
        int prod = 1;
        f(k,sz) if((j>>k) & 1) prod*=fct[num][k];
        ml[prod] += sn;
    }
}

int calc(int num)
{
    int res = 0;
    
    int sz = fct[num].size();
    
    f(j,(1<<sz))
    {
        int prod = 1;
        f(k,sz) if((j>>k) & 1) prod*=fct[num][k];
            
        if((__builtin_popcount(j) & 1)) res -= ml[prod];
        else res += ml[prod];
    }
    
    return res;
}

void solve()
{
   int n,q;
    cin >> n >> q;
    
   f(i,n) cin >> a[i];
    
   while(q--)
   {
       int x;
       cin >> x;
       x--;
       
       if(fre[x] == 0)
       {
           res += calc(a[x]);
           add(a[x],1);
       }
       else
       {
           add(a[x],-1);
           res -= calc(a[x]);
       }
       
       fre[x]^=1;
       cout << res << '\n';
   }
}

signed main()
{
    pre();
    
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}