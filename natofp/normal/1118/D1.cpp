#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> a;
long long int n,m;
bool czy(int x)
{
    long long int res=0;
    for(int i=0;i<n;i++)
    {
        int t=i/x;
        res+=max(a[i]-t,0);
    }
    if(res>=m) return true;
    return false;
}

int main()
{
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int lo=1;
    int hi=n;
    if(czy(n)==false) {cout<<-1; return 0;}
    while(lo+1<hi)
    {
        int mid=(lo+hi)/2;
        if(czy(mid)==true) hi=mid;
        else lo=mid;
    }
    while(czy(lo)==false) lo++;
    cout<<lo<<endl;
    return 0;
}