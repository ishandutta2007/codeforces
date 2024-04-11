#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mod=998244353;

int main()
{
    string s; cin>>s;
    string res;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='o') res+='o';
        else
        {
            if(i!=s.length()-1 && s[i+1]=='v') res+='w';
        }
    }
    long long int ile=0;
    for(int i=0;i<res.size();i++)
    {
        if(res[i]=='w') ile++;
    }
    long long int akt=0;
    long long int wynik=0;
    for(int i=0;i<res.size();i++)
    {
        if(res[i]=='o')
        {
            wynik+=akt*ile;
        }
        else
        {
            akt++;
            ile--;
        }
    }
    cout<<wynik;
    return 0;
}