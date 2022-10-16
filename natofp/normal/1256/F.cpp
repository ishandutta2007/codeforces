#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;

int ilea[26];
int ileb[26];
string s,t;

int dajs(int lo,int hi)
{
    int res=0;
    for(int i=lo;i<=hi;i++)
    {
        for(int j=i-1;j>=lo;j--)
        {
            if(s[j]>s[i]) res++;
        }
    }
    return res;
}

int dajt(int lo,int hi)
{
    int res=0;
    for(int i=lo;i<=hi;i++)
    {
        for(int j=i-1;j>=lo;j--)
        {
            if(t[j]>t[i]) res++;
        }
    }
    return res;
}

int main()
{
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        bool koniec=false;
        int n; cin>>n;
        cin>>s>>t;
        for(int i=0;i<26;i++) ilea[i]=ileb[i]=0;
        for(int i=0;i<n;i++)
        {
            ilea[s[i]-'a']++;
            ileb[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(ilea[i]!=ileb[i])
            {
                cout<<"NO"<<"\n"; koniec=true; break;
            }
        }
        if(koniec) continue;
        for(int i=0;i<26;i++)
        {
            if(ilea[i]>1)
            {
                cout<<"YES"<<"\n";koniec =true; break;
            }
        }
        if(koniec) continue;
        if(dajs(0,n-1)%2==dajt(0,n-1)%2)
        {
            cout<<"YES"<<"\n"; continue;
        }
        bool ok = false;
        for(int len=1;len<=n;len++)
        {
            bool czy[4];
            for(int k=0;k<4;k++) czy[k]=false;
            for(int lo=0;lo<n;lo++)
            {
                if(lo+len-1>=n) break;
                int hi=lo+len-1;
                int xd=dajs(lo,hi);
                int suma=(hi-lo+1)*(hi-lo)/2;
                if((suma-xd)%2!=xd%2) czy[0]=true;
                else czy[1]=true;
                xd=dajt(lo,hi);
                suma=(hi-lo+1)*(hi-lo)/2;
                if((suma-xd)%2!=xd%2) czy[2]=true;
                else czy[3]=true;
            }
            if(czy[0] && czy[3]) ok = true;
            if(czy[1] && czy[2]) ok = true;
        }
        if(ok) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";

    }
    return 0;
}