#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long int res=0;
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0) a[i]*=-1;
    }
    sort(a,a+n);
    int prawy=0;
    for(int i=0;i<n;i++)
    {
        while(prawy<n-1 && a[prawy+1]<=a[i]*2) prawy++;
        res+=prawy-i;
    }
    cout<<res;
    return 0;
}