#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    string res="";
    res+=s[0];
    for(int i=1;i<s.length();i++)
    {
        if(res.size()==1 || s[i]!=res[res.size()-1] || s[i]!=res[res.size()-2]) res+=s[i];
    }
    string ans="";
    int roz=0;
    for(int i=0;i<res.size();i++)
    {
        if(roz%2==0)
        {
            roz++;
            ans+=res[i];
        }
        else
        {
            if(res[i]==ans[ans.size()-1]) continue;
            roz++;
            ans+=res[i];
        }
    }
    string wynik;
    if(ans.size()%2==0) wynik=ans;
    else
    {
        for(int i=0;i<ans.size()-1;i++) wynik+=ans[i];
    }
    cout<<n-wynik.size()<<endl;
    cout<<wynik;
    return 0;
}