#include<bits/stdc++.h>
using namespace std;
int ty[205],cnt[205];
int main()
{
    int a,b,x;
    scanf("%d%d%d",&a,&b,&x);
    if(a>b)
    {
        for(int i=0;i<=x;i++)
        {
            ty[i]=i&1,cnt[i]=1;
            if(ty[i])b--;
            else a--;
        }
        cnt[0]+=a;
        cnt[1]+=b;
    }
    else
    {
        for(int i=0;i<=x;i++)
        {
            ty[i]=~i&1,cnt[i]=1;
            if(ty[i])b--;
            else a--;
        }
        cnt[1]+=a;
        cnt[0]+=b;
    }
    for(int i=0;i<=x;i++)
        for(int j=0;j<cnt[i];j++)
            printf("%d",ty[i]);
    return 0;
}