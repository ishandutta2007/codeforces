#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve()
{
   int n,k;
    cin >> n >> k;
    
   string a,b;
    cin >> a >> b;
    
    vector<int> fa(26,0),fb(26,0);
    
    for(auto x : a) fa[x-'a']++;
    for(auto x : b) fb[x-'a']++;
    
    f(i,26)
    {
        if(fa[i] < fb[i]) 
        {
            cout <<"NO\n";
            return;
        }
        
        int ext = fa[i] - fb[i];
       
        if( (ext % k) != 0) 
        {
            cout <<"NO\n";
            return;
        }
        
        fa[i+1] += ext;
    }
    
    
    cout <<"YES\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}