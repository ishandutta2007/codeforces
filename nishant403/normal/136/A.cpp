#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
int n,i,j,k;
    
    cin >> n;
    int ans[n];
    
    for(i=1;i<=n;i++)
    {
    cin >> j;
       ans[j-1]=i;
        
    }
    
    f(i,n) cout << ans[i] << " ";
}