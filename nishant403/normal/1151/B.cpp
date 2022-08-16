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
 fast;   
 ll n,m,k=0,i,j;
 string s;
    
    cin >> n >> m;
 
 vector<int> aa(n);
  int a[n][m];
    
    vector< set<int> > ss(n);
    
    f(i,n) f(j,m)
    {
     cin >> a[i][j];   
     ss[i].insert(a[i][j]);  
    }
    
   ll diff = -1;
    
    f(i,n) if(ss[i].size() > 1)  {diff=i; break;}
    f(i,n) k^=a[i][0];
   
    if(diff == -1 && k==0)
    {
      cout <<"NIE";    
        return 0;
    }
    else
    { cout << "TAK\n";
     if(k!=0) f(i,n) cout << 1 << " ";  
    else
    {ll gg = -1;
     f(i,m) if(a[diff][i]!=a[diff][0]){ gg = i+1; break; }  
        
     f(i,n) if(i!=diff) cout << 1 << " " ;   
     else cout << gg << " ";
         return 0;
    }
        
    }
    
}