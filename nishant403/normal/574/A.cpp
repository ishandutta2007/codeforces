#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        int n;
    cin >> n;
    
    int a[n];
    priority_queue<int> P;
    
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<n;i++) P.push(a[i]);
    
    int ans = 0;
    
    while(a[0] <= P.top())
    {
     int x = P.top();
      P.pop();
        
     a[0]++;
      P.push(x-1);
      ans++;
    }
    
    cout << ans;
}