#include <bits/stdc++.h>
using namespace std;
long long cnt[30],c[30][30];
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++) c[j][s[i]-'a']+=cnt[j];
        cnt[s[i]-'a']++;
    }
    long long res=0;
    for(int i=0;i<26;i++)
    {
        res=max(res,cnt[i]);
        for(int j=0;j<26;j++) res=max(res,c[i][j]);
    }
    cout<<res;
}