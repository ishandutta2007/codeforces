#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    fast;
    
    int n,x,y;
    cin >> n >> y;
    
    int a[131073]={0};
    
    f(i,n)
    {
     cin >> x;
     a[x]++;
    }
    
    int ans =0;
    
    if(y!=0)   f(i,100001) ans+=a[i^y]*a[i];
    else f(i,100001) ans+=a[i]*(a[i]-1);
    
   cout << (ans>>1); 
        
    
    
    
    
    
}