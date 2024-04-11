#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax = 1e6+5;
int n,k;
int a[nax];
int tt[nax];

void prep()
{
    for(int i=1;i<nax;i++) a[i]=i;
    for(int i=2;i<nax;i++)
    {
        if(a[i]==i)
        {
            for(int j=i;j<nax;j+=i)
            {
                a[j]=min(a[j],i);
            }
        }
    }
    tt[1]=1;
    for(int i=2;i<nax;i++)
    {
        int dd=a[i];
        int cnt=0;
        int akt=i;
        while(akt>1)
        {
            if(akt%dd==0)
            {
                akt/=dd;
                cnt++;
            }
            else break;
        }
        int ile=1;
        for(int j=0;j<cnt;j++) ile*=dd;
        tt[i]=tt[i/ile]*(ile-ile/dd);
    }
}
int main()
{
    cin>>n>>k;
    prep();
    if(k==1)
    {
        cout<<3<<endl;
        return 0;
    }
    ll res=0;
    vector<int> jd;
    for(int i=3;i<=n;i++) jd.push_back(tt[i]);
    sort(jd.begin(),jd.end());
    res=2;
    for(int i=0;i<k;i++) res+=jd[i];
    cout<<res;
    return 0;
}