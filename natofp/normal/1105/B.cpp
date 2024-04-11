#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int tab[5555];
    memset(tab,0,sizeof tab);
    int akt=1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1]) {akt++;}
        else
        {
            tab[s[i-1]-'a']+=akt/k;
            akt=1;
        }
    }
    tab[s[n-1]-'a']+=akt/k;
    int ans=0;
    for(int i=0;i<26;i++) ans=max(ans,tab[i]);
    cout<<ans;
    return 0;
}