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
    int n;
    cin >> n;
    
    int a[n];
    int f1=0,f2=0;
    
    f(i,n) 
    {  
        cin >> a[i];
        
       if(a[i]%2==0) f1=1;
        else f2=1;
    }
    
    if(f1==1 && f2==1)
    {
     sort(a,a+n);
        for(int i=0;i<n;i++) cout << a[i] << " ";
    }
    else
    {
     for(int i=0;i<n;i++) cout << a[i] << " ";   
    }
    
}