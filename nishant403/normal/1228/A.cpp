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

void diff(int x)
{
    int nn = x;
    
    set<int> ss;
    int cn = 0;
    while(x)
    {
     ss.insert(x%10);
     x/=10;
     cn++;
    }
    
    if(cn == ss.size())
    {
      cout << nn ;exit(0);   
    }
    
}

void solve()
{
  
    int l;
    int r;
    cin >> l;
    cin >> r;
    for(int i=l;i<=r;i++)
        diff(i);
    cout<<-1;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}