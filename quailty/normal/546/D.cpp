#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXV=5000000;
bool np[MAXV+5];
ll cnt[MAXV+5],ans[MAXV+5];
void build()
{
    for(int i=2;i<=MAXV;i++)
    {
        if(!np[i])
        {
            for(int j=i;j<=MAXV;j+=i)
            {
                cnt[j]++;
                np[j]=1;
            }
            ll t=i;
            while(1)
            {
                t=t*i;
                if(t>MAXV)break;
                for(int j=t;j<=MAXV;j+=t)cnt[j]++;
            }
        }
    }
    for(int i=2;i<=MAXV;i++)
        ans[i]=ans[i-1]+cnt[i];
}
int main()
{
    build();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%I64d\n",ans[a]-ans[b]);
    }
    return 0;
}