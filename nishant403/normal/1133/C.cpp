#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int ans=0;
    int l,r;

    cin >> n;
    
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    sort(a,a+n);
    
    l=0;
    r=0;
    
    for(int i=0;i<n;i++)
    {
        while(r!=l && a[r]-a[l] > 5) l++;
        ans=max(ans,r-l+1);
        
        r++;
    }
    cout << ans;
}