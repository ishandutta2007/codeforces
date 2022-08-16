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

int dp[26][5005][26];

void solve()
{
    string s;
    cin >> s;
    
    int ways = 0;
    
    int n = s.length();
    
    f(i,n) f(j,n) dp[s[i]-'a'][(j-i+n)%n][s[j]-'a']++;
    
    int occ[26] = {0};
    
    f(i,26) 
    {
        int temp = 0;
        
        f(k,5000)
        {
        
        int val = 0;
        f(j,26) if(dp[i][k][j] == 1)val++;
        temp=max(temp,val);
        
        }
        
        ways+=temp;
    }
    
    cout << fixed << setprecision(6) << (double)ways/n;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}