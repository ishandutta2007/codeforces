#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int naj=a[0];
    for(int i=0;i<n;i++) naj=max(naj,a[i]);
    int res=0;
    int akt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==naj) akt++;
        else
        {
            res=max(res,akt);
            akt=0;
        }
    }
    res=max(res,akt);
    cout<<res;
    return 0;
}