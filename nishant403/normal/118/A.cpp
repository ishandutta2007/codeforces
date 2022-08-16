#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
 fast;
 string s;
    cin >> s;
    
   string b="aeiouyAEIOUY"; 
    
    for(auto x : s)
    {
        int flag =1;
        
        for(int i=0;i<12;i++) if(x==b[i]) flag=0;
        
            if(flag) { cout << '.' ;
              if( x>='A' && x<='Z') cout << char(x-'A'+'a');
                     else cout << x;}
    }
}