#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 


int main()
{
    int T;
    
    cin >> T;
    while(T--)
    {
        
        ll n,k,i,j,ans=0;     
        cin >> n;
    
        ll t=1;
        
        f(i,9)
        {
             if(i) t=t*2;
            
            if(t >= n) break;
            
             vector<int> a,b;
 
             f(j,n) if( ((j/t) % 2) == 0) a.pb(j+1);
                    else b.pb(j+1);
    
            cout << a.size() << " " << b.size() <<  " " ;
             for(auto x : a) cout << x << " " ;
             for(auto x : b) cout << x << " " ;
             cout << endl;
             cout.flush();
     
            cin >> k;
            ans=max(ans,k);
        }
    
     cout << -1 << " " <<  ans << endl;
     cout.flush();
    }
}