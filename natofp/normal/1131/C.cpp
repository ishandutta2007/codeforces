#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            ans[i/2]=a[i];
        }
        else
        {
            ans[n-1-i/2]=a[i];
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}