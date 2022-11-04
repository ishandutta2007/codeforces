#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    for(int i=0,j=0;i<(int)s.size();i++)
    {
        j+=(s[i]==t[j]);
        if(j==(int)t.size())
        {
            cout<<"automaton"<<endl;
            return 0;
        }
    }
    int cnt[26]={0};
    for(int i=0;i<(int)s.size();i++)
        cnt[s[i]-'a']++;
    for(int i=0;i<(int)t.size();i++)
        cnt[t[i]-'a']--;
    bool isok=1;
    for(int i=0;i<26;i++)
        isok&=(cnt[i]>=0);
    if(isok)
    {
        cout<<(s.size()==t.size() ? "array" : "both")<<endl;
        return 0;
    }
    cout<<"need tree"<<endl;
    return 0;
}