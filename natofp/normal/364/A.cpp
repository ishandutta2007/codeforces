#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> pre;
unordered_map<int,int> wyn;
unordered_map<int,int> pom;

string s;
int a;
bool ok=true;

vector<int> znajdz(int n)
{
    vector<int> res;
    for(int i=1;i*i<=n;i++)
    {
        if(i*i==n) res.push_back(i);
        else if(n%i==0)
        {
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

void rob(int n)
{
    int ans=0;
    int t=s.length();
    if(ok)
    {
        pre.clear();
    pre.push_back(0);
    pom[0]++;
    for(int i=0;i<t;i++)
    {
        int akt=pre[pre.size()-1];
        akt+=(s[i]-48);
        pom[akt]++;
        pre.push_back(akt);
    }
    ok=false;
    }
    for(int i=0;i<=t;i++)
    {
        int akt=pre[i];
        ans+=pom[n+akt];
    }
    wyn[n]=ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a; cin>>s;
    vector<int> dzielniki=znajdz(a);
    for(int i=0;i<dzielniki.size();i++)
    {
        rob(dzielniki[i]);
    }
    long long int res=0;
    if(a!=0)
    {
        for(int i=0;i<dzielniki.size();i++)
        {
            int t=dzielniki[i];
            res+=(long long int)wyn[t]*wyn[a/t];
        }
        cout<<res;
        return 0;
    }
    else
    {
        vector<int> dlugosci;
        int akt=0;
        if(s[0]=='0') akt=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='0') akt++;
            else
            {
                if(akt>0) dlugosci.push_back(akt);
                akt=0;
            }
        }
        if(akt>0) dlugosci.push_back(akt);
        long long int n=s.length();
        for(int i=0;i<dlugosci.size();i++)
        {
            long long int t=dlugosci[i];
            res+=((n)*(n+1)/2*t*(t+1)/2);
        }
        res*=2;
        for(int i=0;i<dlugosci.size();i++)
        {
            for(int j=0;j<dlugosci.size();j++)
            {
                long long int x,y;
                x=dlugosci[i];
                y=dlugosci[j];
                long long int xd=(x)*(x+1)/2*y*(y+1)/2;
                res-=xd;
            }
        }
        cout<<res<<endl;

    }
    return 0;
}