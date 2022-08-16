#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 406;
int n,m;
string s,t;

bool check()
{
    int pt = 0;
    f(i,n) if(s[i] == t[pt] && pt<m) pt++;
    return (pt == m);     
}

vector< bitset<N> > dp(N);
vector< bitset<N> > dp2(N);
           
bool go(int id)
{
    bitset<N> s3[26];
    for(int i=id+1;i<m;i++) s3[t[i]-'a'][i-id] = 1;
    
    int p1 = 0;
    int p2 = id+1;

    int l = id+1;
    int r = m-l;
    
    for(int i=0;i<=l;i++) dp[i] = 0;
    
    dp[0][0] = 1;
    
    for(int i=1;i<=n;i++)
    {   
        for(int j=0;j<=l;j++)
        {
         dp2[j] = dp[j];
         dp2[j] = dp2[j] | ((dp[j]<<1) & (s3[s[i-1]-'a']));
        
         if(j>0 && s[i-1] == t[j-1])  dp2[j] = dp2[j] | dp[j-1];     
        }
        
        swap(dp,dp2);
    }
       
    return dp[l][r];
}

void solve()
{
   cin >> s >> t; 
    
   n = s.length();
   m = t.length();
    
   if(check())
   {
       cout <<"YES\n";
       return;
   }
    
   for(int i=0;i<=m-2;i++)
     if(go(i))
     {
       cout <<"YES\n";
       return;
     }
    
   cout <<"NO\n"; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}