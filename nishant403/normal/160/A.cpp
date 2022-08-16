#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
 fast;
    
  int n;
    cin >> n;
    int sum=0;
    int a[n];
    for(int i=0;i<n;i++){
             cin >> a[i];   
        sum+=a[i];
}
    
    sort(a,a+n);
    reverse(a,a+n);
    
    
    int x= 0;
    for(int i=1;i<=n;i++)
    {
        x+=a[i-1];   
        if(x> sum/2){cout << i; return 0;}   
        
    }
    
}