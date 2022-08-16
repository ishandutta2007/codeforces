#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)

int main()
{
int i,j,k,n,m,h;
    cin >> n >> m >> h;
    
int nn[n];
int mm[m];
int hh[n][m];    
    
f(i,m) cin >> mm[i];    
f(i,n) cin >> nn[i];
    
f(i,n) f(j,m) cin >> hh[i][j];
    f(i,n) 
    {
        f(j,m) 
        if( hh[i][j]) cout << min(nn[i],mm[j]) <<  " " ;  
        else cout << 0 << " " ;
     cout << "\n";
    }
    
}