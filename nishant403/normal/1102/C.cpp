#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,x,y;
    int count=0;
    cin >> n >> x >> y;
    
    int a[n];
    for(int i=0;i<n;i++) 
    {
        cin >> a[i];
    if(a[i]<=x) count++;
    }
    if(x > y)
    { cout << n;
    return 0;
    }
    else
    {
    if(count%2==0) cout << count/2;
    else cout << (count+1)/2;
        
    }
    
    
    return 0;
}