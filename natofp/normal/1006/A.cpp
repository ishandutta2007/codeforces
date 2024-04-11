#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a= new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==1) cout<<a[i]<<" ";
        else cout<<a[i]-1<<" ";
    }
    return 0;
}