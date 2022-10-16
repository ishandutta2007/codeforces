#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    int naj=a[0];
    for(int i=1;i<n;i++) naj=max(naj,a[i]);
    long long int left=0;
    long long int akt=0;
    left=n;
    for(int i=0;i<n;i++)
    {
        if(a[i]>akt) akt++;

    }
    left+=a[n-1]-akt;
    cout<<sum-left;
    return 0;
}