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

void solve()
{
  string p,h;
    cin >> p >> h;
    
    int cn[26] = {0};
    
    for(auto x : p) cn[x-'a']++;
    
    int temp[26] = {0};
    
    if(h.size() < p.size())
    {
        cout<<"NO\n"; return;
    }
    
    for(int i=0;i<(int)p.size()-1;i++) temp[h[i]-'a']++;
    
    
    for(int i=(int)p.size()-1;i<h.size();i++)
    {
        if(i>=p.size()) temp[h[i-(int)p.size()]-'a']--;
        temp[h[i]-'a']++;
        
        int flag = 1;
        
        f(j,26) 
            if(temp[j] != cn[j]) flag = 0;
        
       if(flag == 1)
        {
            cout<<"YES\n"; return;
        }
            
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