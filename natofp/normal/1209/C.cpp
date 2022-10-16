#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void f(string s)
{
    vector<char> res;
    int n=s.length();
    for(int i=0;i<n;i++) res.push_back('0');
    int ile[10];
    for(int i=0;i<10;i++) ile[i]=0;
    for(int i=0;i<n;i++)
    {
        ile[s[i]-'0']++;
    }
   // cout<<"JD"<<endl;
    //cout<<ile[0]<<endl;
    //cout<<"JD"<<endl;
    int akt=0;
    for(int i=0;i<n;i++)
    {
        while(ile[akt]==0) akt++;
        if((s[i]-'0')==akt)
        {
            ile[akt]--;
            res[i]='1';
        }
    }
    for(int i=0;i<n;i++)
    {
        if(res[i]=='0') res[i]='2';
    }
    vector<int> b;
   // cout<<"XD"<<endl;
   // for(int i=0;i<n;i++) cout<<res[i];
   // cout<<"XD"<<endl;
    for(int i=0;i<n;i++)
    {
        if(res[i]=='1') b.push_back((int)(s[i]-'0'));
    }
     for(int i=0;i<n;i++)
    {
        if(res[i]=='2') b.push_back((int)(s[i]-'0'));
    }
    for(int i=1;i<n;i++)
    {
        if(b[i]<b[i-1])
        {
            cout<<"-"<<"\n";
            return;
        }
    }
    for(int i=0;i<n;i++) cout<<res[i];
    cout<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string s; cin>>s;
        f(s);
    }

    return 0;
}