#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1505;
char s[MAXN];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int m,res=0;
        char t[5];
        scanf("%d%s",&m,t);
        for(int l=1,r=1;l<=n;l++)
        {
            while(m>=(s[r]!=*t) && r<=n)m-=(s[r++]!=*t);
            res=max(res,r-l);
            m+=(s[l]!=*t);
        }
        printf("%d\n",res);
    }
    return 0;
}