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
const int N = 2e5 + 10;

vector<pii> mp[N];

void pre()
{
   for(int i=2;i<N;i++)
       if(mp[i].empty())
   {
       for(int j=i;j<N;j+=i)
       {
           int tmp = j , pw = 0;
           
           while(tmp % i == 0)
           {
               tmp/=i;
               pw++;
           }
           
           if(pw > 0) mp[j].pb({i,pw});
       } 
   }
}

int n,q;
int res = 1;

int a[N];
map<int,int> cur[N];
int fre[N];

void add(int i,int p,int k)
{
    if(cur[i].find(p) == cur[i].end()) fre[p]++;
    cur[i][p]+=k;
    
    if(fre[p] == n) 
    {
        int mn = N;
        
        f(j,n) mn = min(mn,cur[j][p]);
        f(j,mn) res = (res*p)%MOD;
        
        for(int j=0;j<n;j++)
        {
            cur[j][p]-=mn;
            if(cur[j][p] == 0) 
            {
                cur[j].erase(p);
                fre[p]--;
            }
        }
    }
}

void solve()
{
   cin >> n >> q;
   f(i,n) cin >> a[i];
   f(i,n) for(auto z : mp[a[i]]) add(i,z.F,z.S); 
    
   while(q--)
   {
       int x,y; 
       cin >> x >> y;
       for(auto z : mp[y]) add(x-1,z.F,z.S);
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