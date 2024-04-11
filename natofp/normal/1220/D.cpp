#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll> res;
int lev=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<ll> xd;
    vector<ll> kappa;
    for(int i=0;i<n;i++)
    {
        ll x; cin>>x;
        xd.push_back(x);
    }
    kappa=xd;
    vector<ll> a;
    vector<ll> b;
    for(int i=0;i<=62;i++)
    {
        if(xd.size()==0) break;
        a.clear();
        for(int j=0;j<xd.size();j++)
        {
            if(xd[j]%2==1) a.push_back(xd[j]);
            else b.push_back(xd[j]/2);
        }
        if(res.size()<a.size())
        {
            res=a;
            lev=i;
        }
        xd=b;
        b.clear();
    }
    //for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    //cout<<"XD"<<endl;
    vector<ll> odp;
    for(int i=0;i<res.size();i++)
    {
        ll akt=res[i];
        akt*=((1LL)<<lev);
        kappa.push_back(akt);
    }
    sort(kappa.begin(),kappa.end());
    vector<ll> ans;
    for(int i=0;i<kappa.size();i++)
    {
        if(i==0 && kappa.size()>=1)
        {
            if(kappa[i+1]!=kappa[i]) ans.push_back(kappa[i]);
        }
        else if(i==kappa.size()-1 && kappa.size()>=2)
        {
            if(kappa[i-1]!=kappa[i]) ans.push_back(kappa[i]);
        }
        else
        {
            if(kappa[i]!=kappa[i-1] && kappa[i]!=kappa[i+1]) ans.push_back(kappa[i]);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}