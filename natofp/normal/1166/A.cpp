#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int daj(int n)
{
    if(n==1) return 0;
    return (n)*(n-1)/2;
}

int main()
{
    int n; cin>>n;
    int ile[26];
    int res=0;
    memset(ile,0,sizeof ile);
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        ile[s[0]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        int cnt=ile[i];
        res+=daj(cnt/2);
        res+=daj(cnt-cnt/2);
    }
    cout<<res;
    return 0;
}