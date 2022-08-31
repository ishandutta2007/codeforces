#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int ans=0;

    cin >> n;
    
    int a[n],b[n];
    
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    
    map<long double,int > hi;
    
    int z=0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]) hi[-b[i]/(long double)a[i]]++;
        
        if(a[i]==0 && b[i]==0 ) z++;
    }
    
    for(auto x : hi) ans=max(ans,x.second); 
    cout << ans+ z;
    
    
    
    
    
    
}