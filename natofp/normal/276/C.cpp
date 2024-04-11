#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n,q; cin>>n>>q;
    long long int * a=new long long int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long int> SUM(n+1,0);
    sort(a,a+n);
    for(int i=0;i<q;i++)
    {
        int x,y; cin>>x>>y;
        x--; y--;
        SUM[x]+=1;
        SUM[y+1]-=1;
    }
    for(int i=1;i<n;i++)
    {
        SUM[i]+=SUM[i-1];
    }
    sort(SUM.begin(),SUM.end()-1);
    long long int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=a[i]*SUM[i];
    }
    cout<<ans;

    return 0;
}