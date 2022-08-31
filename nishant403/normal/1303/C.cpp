#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

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

void solve()
{
   string s;
   cin >> s;
    
   int vis[26] = {0}; 
   int n = s.length();
   
   char res[100];
   f(i,100) res[i] = '0'; 
    
   int cur = 50;
   int l = 50;
   int r = 50;
   res[cur] = s[0]; 
   vis[s[0]-'a'] = 1;  
    
   for(int i=1;i<n;i++)
   {
       if(res[cur+1] == s[i]) cur++;
       else if(res[cur-1] == s[i]) cur--;
       else if(vis[s[i]-'a'] == 1) 
       {
           cout <<"NO\n";
           return;
       }
       else if(res[cur+1] == '0')
       {
           cur++;
           res[cur] = s[i];
           r=cur;
       }
       else if(res[cur-1] == '0')
       {
           cur--;
           res[cur] = s[i];
           l=cur;
       }
       else 
       {
           cout <<"NO\n";
           return;
       }
       
       vis[s[i]-'a'] = 1;
   }
    
    for(int i=0;i<26;i++) if(vis[i] == 0)
    {
        r++;
        res[r] = (char)(i+'a');
    }
    
    cout <<"YES\n";
    for(int i=l;i<=r;i++) cout << res[i];
    cout <<'\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}