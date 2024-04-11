#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
long long int StoI(string s)
{
    long long int w=0;
    long long int x=1;
    for(int i=s.length()-1;i>=0;i--)
    {
        w+=(s[i]-'0')*x;
        x*=10;
    }
    return w;
}

int licz(string s)
{
    int w=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='0') w++;
    }
    return w;
}



vector<string> wyrazy[19];
void solve(int n)
{
    if(n==1)
    {
        for(int i=1;i<10;i++)
        {
            string x="";
            x+=char(i+48);
            wyrazy[n].push_back(x);
        }
    }
    else
    {
        for(int i=0;i<wyrazy[n-1].size();i++)
        {
            if(licz(wyrazy[n-1][i])==3) wyrazy[n].push_back(wyrazy[n-1][i]+"0");
            else if(licz(wyrazy[n-1][i])<3)
            {
                for(int j=0;j<=9;j++)
                {
                    string x="";
                    x+=char(j+'0');
                    wyrazy[n].push_back(wyrazy[n-1][i]+x);


                }
            }
        }
    }
}

vector<string> odp;
vector<long long int>res;


int main()
{
    for(int i=1;i<=18;i++) solve(i);
    odp.push_back("1000000000000000000");
    for(int i=1;i<=18;i++)
    {
        for(int j=0;j<wyrazy[i].size();j++) odp.push_back(wyrazy[i][j]);
    }
    for(int i=0;i<odp.size();i++)
        res.push_back(StoI(odp[i]));
    sort(res.begin(),res.end());
    int t; cin>>t;
    vector<long long int>::iterator it,it2;
    for(int i=0;i<t;i++)
    {
        long long int l,r;
        cin>>l>>r;
        it=lower_bound(res.begin(),res.end(),l);
        it2=upper_bound(res.begin(),res.end(),r);
        cout<<it2-it<<endl;
        
    }





    return 0;
}