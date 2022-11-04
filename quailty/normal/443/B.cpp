#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[405];
bool check(int l,int r)
{
    int len=r-l+1;
    for(int i=l,j=r-len/2+1,k=0;k<len/2;i++,j++,k++)
        if(s[i]!='?' && s[j]!='?' && s[i]!=s[j])return 0;
    return 1;
}
int main()
{
    int k;
    scanf("%s%d",s,&k);
    int n=strlen(s);
    for(int i=0;i<k;i++)
        s[n++]='?';
    int res=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j+=2)
            if(check(i,j))res=max(res,j-i+1);
    printf("%d\n",res);
    return 0;
}