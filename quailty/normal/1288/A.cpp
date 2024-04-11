#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,d;
        scanf("%d%d",&n,&d);
        int t=sqrt(d),res=d;
        for(int i=max(0,t-100000);i<=min(d,t+100000);i++)
            res=min(res,i+(d+i)/(i+1));
        printf("%s\n",(res<=n ? "YES" : "NO"));
    }
    return 0;
}