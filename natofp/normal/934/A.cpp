#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int * a;
    long long int * b;
    a=new long long int[n];
    b=new long long int[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    long long int odp1=a[0]*b[m-1];
    odp1=max(odp1,a[0]*b[0]);
    odp1=max(odp1,a[n-2]*b[m-1]);
    odp1=max(odp1,a[n-2]*b[0]);
    long long int odp2=a[1]*b[m-1];
    odp2=max(odp2,a[1]*b[0]);
    odp2=max(odp2,a[n-1]*b[m-1]);
    odp2=max(odp2,a[n-1]*b[0]);
    cout<<min(odp1,odp2);
    return 0;
}