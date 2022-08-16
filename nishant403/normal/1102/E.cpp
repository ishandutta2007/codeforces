#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    long a[n];
    map<long ,int > m;
    
    long long ans=1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        m[a[i]]=i;
    }
    int key=1;
    
    int i=0,k;
    while(i<n)
    {
        k=m[a[i]];
     for(int j=i;j<=k;j++)
     {
         if(m[a[j]] > k) k=m[a[j]];
         i++;
         
     }
     if(key) { key=0 ;}
    else    ans=(ans*2)%998244353;
    }
    
    
    cout << ans ;
    
}