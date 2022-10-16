#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ans=0;
    int wsk=0;
    for(int i=0;i<n;i++)
    {
        while(wsk<n-1 && a[wsk+1]-a[i]<=5) wsk++;
        ans=max(wsk-i+1,ans);

    }
    cout<<ans;
    return 0;
}