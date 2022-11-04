#include <bits/stdc++.h>
using namespace std;

const int MAXN=1005;
char str[MAXN];
int pre[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str+1);
        int n=strlen(str+1);
        for(int i=1;i<=n;i++)
            pre[i]=pre[i-1]+(str[i]-'0');
        int res=n;
        for(int i=0;i<=n;i++)
            res=min(res,pre[i]+(n-i-(pre[n]-pre[i])));
        for(int i=0;i<=n;i++)
            res=min(res,(i-pre[i])+(pre[n]-pre[i]));
        printf("%d\n",res);
    }
    return 0;
}