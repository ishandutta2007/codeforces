#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<char,int>mp;
char s[305];
int main()
{
    int n;
    scanf("%d%s",&n,s);
    if(n%4)return 0*printf("===");
    mp['A']=mp['G']=mp['C']=mp['T']=n/4;
    for(int i=0;i<n;i++)
        if(s[i]!='?')mp[s[i]]--;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        if(itr->second<0)return 0*printf("===");
    for(int i=0;i<n;i++)
        if(s[i]=='?')
        {
            while(mp.begin()->second==0)mp.erase(mp.begin());
            s[i]=mp.begin()->first;
            mp.begin()->second--;
        }
    return 0*printf("%s",s);
}