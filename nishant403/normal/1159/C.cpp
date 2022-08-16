#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<ll> 
#define int long long  

signed main()
{
 fast;   
 ll n,k,m,i,j;
 string s;
    
  cin >> n >> m;
    
   vl B(n),G(m);
    
    f(i,n) cin >> B[i];
    f(i,m) cin >> G[i];
    
    ll ma=B[0],mi=G[0];
    f(i,n) ma=max(ma,B[i]);
    f(i,m) mi=min(mi,G[i]);
    
    if(ma > mi ) { cout << -1; return 0; }
    
    ll sum =0,cc=0,idx=n-1,power=m-1;
    f(i,n) sum+=(m*B[i]);
    f(i,m) if(mi == G[i]) cc++;
        
    sort(G.begin(),G.end());
    sort(B.begin(),B.end());
    
    f(i,m)
    {
     if(power==0) idx--,power=m-1;
     
        if(G[i]==B[idx]) { if(power==m-1) power++;}
        else if(G[i] > B[idx] ) { sum+=G[i]-B[idx]; }
     
     power--;
        
    }
   
    cout << sum;
}