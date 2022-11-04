#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt;
bool used[1005];
struct people
{
    int w,h;
}s[1005];
bool cmp(people a,people b)
{
    return a.w-a.h>b.w-b.h;
}
bool judge(int h)
{
    memset(used,0,sizeof(used));
    for(int i=1;i<=n;i++)
    {
        if(s[i].h>h)
        {
            if(s[i].w>h)return false;
            used[i]=1;
            cnt++;
        }
    }
    if(cnt>n/2)return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&s[i].w,&s[i].h);
    }
    sort(s+1,s+n+1,cmp);
    int ans=2000000000;
    for(int i=1000;i>=0;i--)
    {
        cnt=0;
        if(!judge(i))break;
        cnt=n/2-cnt;
        int W=0;
        for(int j=1;j<=n;j++)
        {
            if(!used[j])
            {
                if(cnt>0 && s[j].w>s[j].h && s[j].w<=i)
                {
                    W+=s[j].h;
                    cnt--;
                }
                else
                {
                    W+=s[j].w;
                }
            }
            else
            {
                W+=s[j].h;
            }
        }
        ans=min(ans,W*i);
    }
    printf("%d\n",ans);
    return 0;
}