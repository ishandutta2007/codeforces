#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
 
using namespace std;
 
         
 main() {
           
    short int n,a,k;
    cin>>n>>a>>k;
    int m1[a], m2[a], max1=0,ans,u,i,j,k1;
    for (i=0;i<a;i++) 
        cin>>m1[i]>>m2[i];
    
    for (i=1;i<=n-k+1;i++) {
        for (j=i;j<=n-k+1;j++) {
            ans=0;
            for (k1=0;k1<a;k1++) {
               ans+=max(max(min(m2[k1],i+k-1)+1-max(i,m1[k1]),min(m2[k1],j+k-1)+1-max(j,m1[k1])),0); 
            }
            max1=max(max1,ans); 
            
            
        }
    }
    cout<<max1; 
}