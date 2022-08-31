#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(i=0;i<n;i++)

signed main()
{
    fast;
    int i,j,k,n;
    int a,b,x,y;
    
    cin >> n >> a >> b >> x >> y;
    
    int maa = min( (b-a+n)%n+1 , (x-y+n)%n+1);
    
    
    for(int i=0;i<maa;i++)
    {   
        if(a==x) {cout << "YES"; return 0;}  
        
        a++;
        if(a==n+1) a=1;
        
        x--;
        if(x==0) x=n;
    }
    
    cout << "NO";
}