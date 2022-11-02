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
        int n,a[100010];
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        int q[100010],cnt=0;
        q[cnt=1]=a[1];q[cnt=2]=a[2];
        rep(i,n)if(i>2)
        {
            for(;cnt>1&&(a[i]>q[cnt])==(q[cnt]>q[cnt-1]);cnt--);
            q[++cnt]=a[i];
        }
        printf("%d\n",cnt);
        rep(i,cnt)printf("%d%c",q[i]," \n"[i==cnt]);
    }
    return 0;
}