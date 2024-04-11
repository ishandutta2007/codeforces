#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int n;
string ans;
int res=1e9;

void rob(string wzor,string s)
{
    string odp;
    int xd=0;
    for(int i=0;i<n;i++)
    {
        odp+=wzor[i%3];
        if(s[i]!=wzor[i%3]) xd++;
    }
    if(xd<res)
    {
        res=xd;
        ans=odp;
    }
}

int main()
{
    cin>>n;
    string s; cin>>s;
    rob("RGB",s);
    rob("RBG",s);
    rob("BGR",s);
    rob("BRG",s);
    rob("GRB",s);
    rob("GBR",s);
    cout<<res<<endl;
    cout<<ans;
    return 0;
}