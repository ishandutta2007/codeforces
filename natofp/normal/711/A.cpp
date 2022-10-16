#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<string> xd;

int main()
{
    int n; cin>>n;
     bool ok = false;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        if(ok == true)
        {
            xd.push_back(s);
            continue;
        }
        if(s[0]==s[1] && s[0]=='O')
        {
            ok = true;
            s[0]=s[1]='+';
        }
        if(ok == true)
        {
            xd.push_back(s);
            continue;
        }
        if(s[3]==s[4] && s[4]=='O')
        {
            ok = true;
            s[3]=s[4]='+';
        }
        xd.push_back(s);
    }
    if(ok)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++) cout<<xd[i]<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}