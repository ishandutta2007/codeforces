#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int  xd(long long int a)
{
    if(a<0) return (a*-1);
    return a;
}

int main()
{

    int n;
    cin>>n;
    long long int * a;
    a=new long long int[2*n];
    for(int i=0;i<2*n;i++) cin>>a[i];
    sort(a,a+2*n);

    long long naj=(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    for(int i=1;i<(n);i++)
    {
        long long int x=a[2*n-1]-a[0];
        long long int y=a[n-1+i]-a[i];
        long long int k=x*y;

        if(k<naj) naj=k;
    }
    cout<<naj;
    return 0;
}