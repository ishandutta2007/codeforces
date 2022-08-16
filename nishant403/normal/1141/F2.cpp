#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<ll,ll>

bool sortbysec(const pll &a,const pll &b)
{
    if(a.S==b.S) return a.F < b.F;
    return a.S < b.S;
}

int main()
{
 fast;   
 ll n,k,i,j,ans=0,tc=0,lim;
    
 cin >> n;
    
 ll a[n];
 ll pre[n+1];
    
 vector<pll> temp,final,temp2;   
    
 pre[0]=0;
    
 f(i,n) cin >> a[i];   
 f(i,n) pre[i+1]=pre[i]+a[i]; 
    
  map<ll,vector<pll> > sums;
    
   f(i,n)
       f(j,i+1) sums[pre[i+1]-pre[j]].pb({j+1,i+1});
       

   for(auto z : sums)
   {
    temp=z.S;
    tc=0;
    lim=0;
       
    sort(temp.begin(),temp.end(),sortbysec);
        
    for(auto x : temp)
    {
      if(x.F > lim) 
       {
           temp2.pb(x);
           tc++;
           lim=x.S;
       }
    }
       
    if(tc > ans)
    {
    ans=tc;
    final=temp2;
    }
      temp2.clear(); 
       
   }
    
    cout << ans << "\n";
    for(auto x : final) cout << x.F << " " << x.S << "\n";
    
   return 0;
}