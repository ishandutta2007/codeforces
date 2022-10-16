#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n>>k;
    long long int res=0;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    vector<int> b;
    for(int i=1;i<n;i++)
    {
        b.push_back(a[i]-a[i-1]);
    }
    sort(b.begin(),b.end());
    res=a[n-1]-a[0];
    int roz=b.size()-1;
    k--;
    for(int i=roz;i>roz-k;i--)
    {
        res-=b[i];
    }
    cout<<res;
    return 0;
}