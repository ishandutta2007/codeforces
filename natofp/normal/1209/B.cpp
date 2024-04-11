#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int ile[11111];


int main()
{
    int n; cin>>n;
    string s; cin>>s;
    vector<pair<int,int> > a;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        a.push_back({x,y});
    }
    for(int i=0;i<n;i++)
    {
        bool par=0;
        if(s[i]=='1') par=1;
        int start=a[i].second;
        for(int j=0;j<start;j++) ile[j]+=par;
        for(int j=start;j<=10000;j++)
        {
            int akt=j-start;
            int podziel=akt/a[i].first;
            if(podziel%2==0)
            {
                ile[j]+=!par;
            }
            else ile[j]+=par;
        }
    }
    int res=0;
    for(int i=0;i<=10000;i++) res=max(res,ile[i]);
    cout<<res;

    return 0;
}