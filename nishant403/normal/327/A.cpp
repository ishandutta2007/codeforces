#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


signed main()
{
Fast;    
    
    int n;
    cin >> n;
    
    int a[n];
    
    for(int i=0;i<n;i++) cin >> a[i];
    
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
     for(int j=i;j<n;j++)
     {
         int c = 0;
         
       for(int k=0;k<n;k++)
       {
        if(k>=i && k<=j)  c+=(1-a[k]);  
        else c+=a[k];   
       } 
         ans=max(ans,c);
     }  
    }
    
    cout << ans;
}