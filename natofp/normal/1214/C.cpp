#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    string s; cin>>s;
    int bal=0;
    int dol=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') bal++;
        else bal--;
        dol=min(dol,bal);
    }
    if(bal!=0)
    {
        cout<<"No"<<endl; return 0;
    }
    else if(bal==0)
    {
        if(dol==0)
        {
            cout<<"Yes"<<endl; return 0;
        }
        if(dol<=-2)
        {
            cout<<"No"<<endl; return 0;
        }
        if(dol==-1)
        {
            cout<<"Yes"<<endl; return 0;
        }
    }
    return 0;
}