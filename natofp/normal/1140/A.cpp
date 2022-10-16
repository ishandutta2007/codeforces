#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    int i=1;
    while(i<=n)
    {
        int najj=a[i];
        while(i<=n)
        {
            najj=max(najj,a[i]);
            if(i==najj) break;
            else i++;
        }
        res++;
        i++;
    }
    cout<<res;
    return 0;
}