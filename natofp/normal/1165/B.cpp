#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int res=0;
    int akt=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=akt)
        {
            res++;
            akt++;
        }
    }
    cout<<res;
    return 0;
}