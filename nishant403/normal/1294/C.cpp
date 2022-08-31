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
    
    int nn = n;
    
    vi d;
    
    for(int i=2;i*i<=n;i++)
        while(n%i==0)  d.pb(i),n/=i;
    
    if(n>1) d.pb(n);
    
    if(d.size() <= 2) cout <<"NO\n";
    else if(d[0] == d.back())
    {
        if(d.size() < 6) cout <<"NO\n";
        else cout << "YES\n" << d[0] <<" "<< (d[0]*d[0])<<" "<<nn/(d[0]*d[0]*d[0]) << '\n';
    }
    else if(nn/(d[0]*d.back()) != d[0] && nn/(d[0]*d.back()) != d.back())
        cout <<"YES\n"<<d[0]<<" "<<d.back()<<" "<<nn/(d[0]*d.back()) << '\n';
    else cout <<"NO\n";    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}