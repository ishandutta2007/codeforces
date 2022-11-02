#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#define mo 1000000007
using namespace std;
int n,ans,x[200000];
char ch[200000];
int main()
{
    scanf("%d\n",&n);
    for (int i=0;i<n;i++) ch[i]=getchar();
    for (int i=0;i<n;i++) scanf("%d",&x[i]);
    ans=-1;
    for (int i=0;i<n-1;i++)
    {
        if ((ch[i]=='R')&&(ch[i+1]=='L'))
        {
            int tmp=(x[i+1]-x[i])/2;
            if ((ans==-1)||(ans>tmp)) ans=tmp;
        }
    }
    printf("%d",ans);
    return 0;
}