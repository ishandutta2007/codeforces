#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
int a[nax];
int suf[nax];

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x<0) x=-1;
        else x=1;
        a[i]=x;
    }
    int ileminus=0;
    int ileplus=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1) ileminus++;
        else ileplus++;
    }
    int ileplussufix=0;
    int ileminussufix=0;
    ileplussufix++;
    int last=1;
    suf[n+1]=1;
    for(int i=n;i>=1;i--)
    {
        if(a[i]==-1) suf[i]=-suf[i+1];
        else suf[i]=suf[i+1];
    }
    for(int i=n;i>=2;i--)
    {
        if(a[i]==1)
        {
            if(last==1)
            {
                ileplussufix++;
            }
            else ileminussufix++;
        }
        else
        {
            if(last==1) last=-1;
            else last=1;
            if(last==1)
            {
                ileplussufix++;
            }
            else ileminussufix++;
        }
    }
    //cout<<ileminussufix<<" "<<ileplussufix<<endl;
    int znak=1;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        //cout<<i<<" "<<ileminussufix<<" "<<ileplussufix<<" "<<ileminus<<" ";
        if(ileminus%2==0)
        {
            //cout<<"XD"<<" "<<i<<endl;
            res+=ileplussufix;
        }
        else res+=ileminussufix;
        if(suf[i+2]==-1) ileminussufix--;
        else ileplussufix--;
        if(a[i+1]==-1) ileminus--;
        else ileplus--;
        //cout<<res<<endl;
    }
    long long int k=n;
    long long int xd=k*(k+1)/2;
    cout<<xd-res<<" "<<res<<endl;
    return 0;
}