#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x,k=0;
        scanf("%d%d%s",&n,&x,s);
        for(int i=0;i<n;i++)
            k+=(s[i]=='0' ? 1 : -1);
        int b=0,inf=0,res=0;
        for(int i=0;i<n && !inf;i++)
        {
            if(k==0)inf|=(b==x);
            else res+=((x-b)%k==0 && (x-b)/k>=0);
            b+=(s[i]=='0' ? 1 : -1);
        }
        if(inf)printf("-1\n");
        else printf("%d\n",res);
    }
    return 0;
}