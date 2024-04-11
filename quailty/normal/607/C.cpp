#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
char s[MAXN],t[MAXN];
int nxt[MAXN];
void kmp(char str[],int len)
{
    nxt[0]=-1;
    for(int i=0;i<len-1;i++)
    {
        int p=nxt[i];
        while(p!=-1 && str[i+1]!=str[p+1])p=nxt[p];
        nxt[i+1]=(str[i+1]==str[p+1] ? p+1 : p);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    n--;
    scanf("%s%s",s,t);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='N')s[i]='S';
        else if(s[i]=='S')s[i]='N';
        else if(s[i]=='W')s[i]='E';
        else if(s[i]=='E')s[i]='W';
    }
    reverse(s,s+n);
    kmp(s,n);
    int p=-1;
    for(int i=0;i<n;i++)
    {
        if(p==n-1)p=nxt[p];
        while(p!=-1 && t[i]!=s[p+1])p=nxt[p];
        p=(t[i]==s[p+1] ? p+1 : p);
    }
    printf("%s\n",(p>=0 ? "NO" : "YES"));
    return 0;
}