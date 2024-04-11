#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int sum1,sum2;
    sum1=0;
    sum2=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0) sum1+=a[i];
        else sum2+=a[i];
    }
    int ans=0;
    int akt1=0;
    int akt2=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0) sum1-=a[i];
        else sum2-=a[i];
        if(akt1+sum2==akt2+sum1) ans++;
        if(i%2==0) akt1+=a[i];
        else akt2+=a[i];
    }
    cout<<ans;
    return 0;
}