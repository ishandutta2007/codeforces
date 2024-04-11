#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,c[100010];scanf("%d",&n);
        rep(i,n)c[i]=0;
        int pos=-1;
        rep(i,n)
        {
            int k;scanf("%d",&k);
            bool flag=0;
            rep(j,k)
            {
                int x;scanf("%d",&x);
                if(!c[x]&&!flag)c[x]=1,flag=1;
            }
            if(!flag)pos=i;
        }
        if(pos==-1)puts("OPTIMAL");
        else
        {
            puts("IMPROVE");
            printf("%d ",pos);
            rep(i,n)if(!c[i]){printf("%d\n",i);break;}
        }
    }
    return 0;
}