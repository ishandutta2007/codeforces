#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int res=0;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n-1;i++)
    {
        if(a[i]>a[i-1] && a[i]>a[i+1]) res++;
        if(a[i]<a[i-1] && a[i]<a[i+1]) res++;
    }
    cout<<res;
    return 0;
}