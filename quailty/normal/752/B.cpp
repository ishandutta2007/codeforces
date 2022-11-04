#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int go[26];
char s[1005],t[1005];
int main()
{
    scanf("%s%s",s,t);
    memset(go,-1,sizeof(go));
    for(int i=0;s[i];i++)
    {
        int l=s[i]-'a',r=t[i]-'a';
        if(go[l]>=0 && go[l]!=r)return 0*printf("-1");
        if(go[r]>=0 && go[r]!=l)return 0*printf("-1");
        go[l]=r;
        go[r]=l;
    }
    int res=0;
    for(int i=0;i<26;i++)
        res+=(go[i]>i);
    printf("%d\n",res);
    for(int i=0;i<26;i++)
        if(go[i]>i)printf("%c %c\n",i+'a',go[i]+'a');
    return 0;
}