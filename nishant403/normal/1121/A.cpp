#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,n) for(i=0;i<n;i++)
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main()
{
    fio;
    ll n,m,k,i,j,ans=0;
    
    
    
    cin >> n >> m >> k;
    
    int a[n],b[n];
    
    f(i,n) cin >> a[i];
    f(i,n) cin >> b[i];
    
    int c[k];
    
    vector<tuple<ll, ll,ll > > ms;
    
    f(i,n) ms.push_back(make_tuple(b[i],a[i],i+1));
    
    f(i,k) cin >> c[i];
    
 
    sort(ms.begin(),ms.end());
    vector<ll> s;
    
    f(i,n)
    {
      if(i!=n-1 && get<0> (ms[i]) == get <0> (ms[i+1]) ) continue;  
        
      s.push_back(get<2> (ms[i]) ); 
    
    }
    
    
    f(i,k)
    {
        int key=1;
     f(j,s.size() ) if(s[j] == c[i] ) key=0;   
        
     if(key) ans++;   
    }
    
         cout << ans;
    
    
 return 0;   
}