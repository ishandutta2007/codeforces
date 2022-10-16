#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n,k;
    cin>>n>>k;
    long long int * a;
    a=new long long int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long int akt=0;
    int j=0;
    for(int i=0;i<k;i++)
    {
        while(j<n && a[j]<=akt)
        {
            j++;
        }
        if(j>=n) cout<<0<<endl;
        else
        {
            cout<<a[j]-akt<<endl;
            akt+=(a[j]-akt);
        }
    }
    return 0;
}