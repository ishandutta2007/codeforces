#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int> 
#define pii pair<int,int>

void solve()
{
    int n,x;
    cin >> n;
    
    vi data(n);
    
    f(i,n) cin >> data[i];
    
    sort(data.begin(),data.end());
    
    int q;
    cin >> q;
    while(q--)
    {
     cin >> x;
        
     cout << distance(data.begin(),upper_bound(data.begin(),data.end(),x)) << "\n";   
    }
}

signed main()
{
 Fast;
 solve();
}