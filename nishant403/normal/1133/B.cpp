#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,temp;
    cin >> n >> k;
    int a[k];
    
    for(int i=0;i<k;i++) a[i]=0;
    
    for(int i=0;i<n;i++)
    {
     cin >> temp;
        a[temp%k]++;
    }
    
    int ans=0;
    
    if(k%2)
    for(int i=1;i<=k/2;i++)
       ans+=min(a[i],a[k-i] ); 
    
    else     
    {
    for(int i=1;i<k/2;i++)
       ans+=min(a[i],a[k-i] ); 
    
     ans+=a[k/2]/2;   
    }
        
    ans+=a[0]/2;
    
    cout << ans*2;
    
}