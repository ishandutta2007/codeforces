#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char a[55],b[55],mp[55],s[1005];
int main()
{
    scanf("%s%s%s",a,b,s);
    for(int i=0;i<26;i++)
        mp[a[i]-'a']=b[i]-'a';
    for(int i=0;s[i];i++)
    {
        if(s[i]>='a' && s[i]<='z')
            s[i]=mp[s[i]-'a']+'a';
        else if(s[i]>='A' && s[i]<='Z')
            s[i]=mp[s[i]-'A']+'A';
    }
    return 0*printf("%s",s);
}