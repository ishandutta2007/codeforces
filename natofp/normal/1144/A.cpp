#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool czy(string s)
{
    int a[26];
    memset(a,0,sizeof a);
    for(int i=0;i<s.length();i++)
    {
        a[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(a[i]>1) return false;
    }
    int idx=0;
    while(idx<26 && a[idx]==0) idx++;
    int j=500;
    for(int i=idx+1;i<26;i++)
    {
        if(a[i]==0)
        {
            j=i;
            break;
        }
    }
    for(int i=j;i<26;i++)
    {
        if(a[i]>0) return false;
    }
    return true;
}


int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        bool ok =czy(s);
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}