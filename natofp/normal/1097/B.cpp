#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int ans;
    for(int i=0;i<(1<<n);i++)
    {
        ans=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j)) ans+=a[j];
            else ans-=a[j];
        }
        if(ans%360==0) {cout<<"YES"; return 0;}
    }
    cout<<"NO";
    return 0;
}