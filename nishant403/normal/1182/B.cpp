#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    fast;
    
    int n,m;
    cin >> n >> m;
    
    string s[n];
    
    f(i,n) cin >> s[i];
    
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-1;j++)
           if(s[i][j]=='*' && s[i-1][j]=='*' && s[i+1][j]=='*' && s[i][j+1]=='*' && s[i][j-1]=='*')
    {
       s[i][j] = '.'; 
        
     for(int k=i+1;k<n;k++) if(s[k][j]=='*') s[k][j]='.'; else break;
     for(int k=i-1;k>=0;k--) if(s[k][j]=='*') s[k][j]='.'; else break;
     for(int k=j+1;k<m;k++) if(s[i][k]=='*') s[i][k]='.'; else break;
     for(int k=j-1;k>=0;k--) if(s[i][k]=='*') s[i][k]='.'; else break;
        
 
        int ff = 0; 
         
      for(int l=0;l<n;l++)  
         for(int y=0;y<m;y++)
           if(s[l][y] == '*') ff=1;
        
         if(ff==0) cout << "YES";
         else cout << "NO";
         
         return 0;
    }
        
        
    cout << "NO";
}