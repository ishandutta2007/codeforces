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
string a,b;
cin >> a >> b;
    
int cn = 0,ans = 0;
    
for(auto x : b) if(x=='1') cn++;
    
int x = a.length();
int y = b.length();    
    
vi pre(x,0);
        
for(int i=1;i<=x;i++) 
{
 pre[i] = pre[i-1] + (a[i-1]=='1');   
}
    
for(int i=1;i<=x-y+1;i++)
if(cn % 2 == (pre[i+y-1]-pre[i-1])%2) ans++;   

    
cout << ans;
    
}

signed main()
{
    fast;
    solve();
}