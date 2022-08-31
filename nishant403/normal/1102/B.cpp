#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   int n,k;
   cin >> n >> k;
   int a[n];
   int max=0;
   int count[5001]{0}; 
   int colors[5001]={0};
   for(int i=0;i<n;i++)
   {  cin >> a[i];
    count[a[i]]++;
    
    if(count[a[i]] > max) max=count[a[i]];
   } 
   
   
     int ans[n];
     int colorcount=0;
     
     colors[0]=1;
     for(int i=1;i<=5000;i++)
     {
     colors[i]=colors[i-1]+count[i-1]; 
     if(colors[i]>k) colors[i]=1;
     } 
     
     
     
     
    if(max >  k || k > n) cout << "NO";
    else
    {
        cout << "YES\n";
    
    for(int i=0;i<n;i++)
    {
        if(colors[a[i]]>k) colors[a[i]]=1;
        
    ans[i]= colors[ a[i] ];
    colors[a[i]]++;
    cout << ans[i] << " ";
    }
    
    }
    return 0;
}