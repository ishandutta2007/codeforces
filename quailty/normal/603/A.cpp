#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int res=1,la=0;
    for(int i=1;i<n;i++)
        if(s[i]!=s[la])
        {
            res++;
            la=i;
        }
    int isok[2]={0,0};
    int l,r;
    for(l=1;l<n;l++)
        if(s[l]==s[l-1])
        {
            isok[0]=1;
            break;
        }
    for(r=l;r<n-1;r++)
        if(s[r]==s[r+1])
        {
            isok[1]=1;
            break;
        }
    res+=isok[0]+isok[1];
    printf("%d\n",res);
    return 0;
}