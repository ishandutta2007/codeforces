#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n+1];
    bool ok1=false;
    bool ok2=false;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0) ok1=true;
        else ok2=true;
    }
    if(ok1 && ok2)
    {
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        return 0;
    }
    return 0;
}