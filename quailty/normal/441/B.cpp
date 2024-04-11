#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int now[3005],la[3005];
int main()
{
    int n,v;
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        now[a]+=b;
    }
    int res=0;
    for(int i=1;i<=3001;i++)
    {
        if(la[i]>=v)res+=v;
        else
        {
            if(now[i]>=v-la[i])
            {
                now[i]-=v-la[i];
                res+=v;
            }
            else
            {
                res+=now[i]+la[i];
                now[i]=0;
            }
        }
        la[i+1]+=now[i];
    }
    return 0*printf("%d",res);
}