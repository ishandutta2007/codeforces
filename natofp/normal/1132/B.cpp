#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    long long int * a=new long long int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int m; cin>>m;
    vector<int> xd;
    for(int i=0;i<m;i++)
    {
        int x; cin>>x;
        xd.push_back(x);
    }
    sort(a,a+n);
    long long int res=0;
    for(int i=0;i<n;i++) res+=a[i];
    for(int i=0;i<m;i++)
    {
        int k=xd[i];
        res-=a[n-k];
        cout<<res<<"\n";
        res+=a[n-k];
    }
    return 0;
}