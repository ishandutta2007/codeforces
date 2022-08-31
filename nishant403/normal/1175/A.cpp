#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>

signed main()
{    
    Fast;
    
    
    int t;
    cin >> t;
    while(t--)
    {
        
    int n,i,j,k,ans = 0;
    string s;
        
     cin >> n >> k;   
            
        
       while(n!=0)
       {
           if(n%k==0) {n/=k; ans++;}
           else {  int l = n%k; n-=l; ans+=l;    }
       }
        
        cout << ans << "\n";
    }
    
    
    
}