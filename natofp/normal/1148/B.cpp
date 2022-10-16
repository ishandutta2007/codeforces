#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long int INF=-1e18;

int main()
{
    long long int n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    if(k>=n || k>=m)
    {
        cout<<-1<<endl;
        return 0;
    }
    long long int* loty1=new long long int[n+1];
    for(int i=1;i<=n;i++) cin>>loty1[i];
    for(int i=1;i<=n;i++) loty1[i]+=ta;
    long long int* loty2=new long long int[m+1];
    for(int i=1;i<=m;i++) cin>>loty2[i];
    long long int res=INF;
    int wsk=1;
    while(wsk<=m && loty2[wsk]<loty1[1]) wsk++;
    if(wsk+k>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    else res=loty2[wsk+k]+tb;
    for(int i=2;i<=k+1;i++)
    {
        while(wsk<=m && loty2[wsk]<loty1[i]) wsk++;
        // usunelismy i-1 lotow typu A
        if(wsk+k-i+1<=m) res=max(res,loty2[wsk+k-i+1]+tb);
        else
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    if(res==INF) cout<<-1;
    else cout<<res;
    return 0;
}