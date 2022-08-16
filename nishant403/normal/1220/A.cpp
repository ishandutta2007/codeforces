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
  int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    map<char,int> mp;
    
    for(auto  x : s) mp[x]++;
    
    string a="one";
    string b="zero";
    
    int ones = 1e10;
    
    for(auto x : a) ones=min(ones,mp[x]);
    
    f(i,ones) cout << 1 <<" ";
                     
    for(auto x : a) mp[x]-=ones;
    
    int zeros = 1e10;
    
    for(auto x :b)zeros=min(zeros,mp[x]);
    
    f(i,zeros) cout << 0 <<" ";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}