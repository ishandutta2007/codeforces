#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    string s,t; cin>>s>>t;
    int ile=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') ile++;
        if(t[i]=='a') ile++;
    }
    if(ile%2==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    vector<int> xd1;
    vector<int> xd2;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            if(s[i]=='a') xd1.push_back(i+1);
            else xd2.push_back(i+1);
        }
    }
    int roz=(int)xd1.size();
    if(roz%2==0)
    {
        cout<<(xd1.size()+xd2.size())/2<<endl;
        for(int i=0;i<xd1.size();i+=2)
        {
            int kol1=xd1[i];
            int kol2=xd1[i+1];
            cout<<kol1<<" "<<kol2<<"\n";
        }
        for(int i=0;i<xd2.size();i+=2)
        {
            int kol1=xd2[i];
            int kol2=xd2[i+1];
            cout<<kol1<<" "<<kol2<<"\n";
        }
    }
    else
    {
        int wyn=xd1.size()/2+xd2.size()/2;
        wyn+=2;
        cout<<wyn<<endl;
        for(int i=0;i<xd1.size()-1;i+=2)
        {
            int kol1=xd1[i];
            int kol2=xd1[i+1];
            cout<<kol1<<" "<<kol2<<"\n";
        }
        for(int i=0;i<xd2.size()-1;i+=2)
        {
            int kol1=xd2[i];
            int kol2=xd2[i+1];
            cout<<kol1<<" "<<kol2<<"\n";
        }
        int kol1=xd1.back();
        int kol2=xd2.back();
        cout<<kol1<<" "<<kol1<<endl;
        cout<<kol1<<" "<<kol2<<endl;
    }
    return 0;
}