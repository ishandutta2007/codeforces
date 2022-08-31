#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
Fast;    
    
    int n,m,x,y,z;
    cin >> n;
    
     vector<pair<pii,int> > data(n);
    
    f(i,n)
    {
     cin >> data[i].F.S >> data[i].F.F;
     data[i].S = i+1; 
    }
    
    sort(data.begin(),data.end());
    
    cin >> m;
    
    multiset<int> table;
    
    queue<int> q[1001];
   
    f(i,m)
    {
     cin >> x;
     table.insert(x);  
     q[x].push(i+1);
    }
    
    int sum = 0;
    
    vector<pii> ans;
    
    for(int i = n-1; i>= 0 ; i--)
    {
     auto p = table.lower_bound(data[i].F.S);   
        
     if(p==table.end()) continue;
    
     sum+=data[i].F.F;   
     
     ans.pb({data[i].S,q[*p].front()});   
     
     q[*p].pop();
     table.erase(p);
    }
    
    cout << ans.size() << " " << sum << "\n";
    
    for(auto x : ans) cout << x.F << " " << x.S << "\n";
}