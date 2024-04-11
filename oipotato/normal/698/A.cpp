#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,f[3]={0,0,0};
    scanf("%d",&n);
    rep(i,n)
    {
        int nf[3];
        int x;scanf("%d",&x);
        if(x==0)nf[0]=min(f[0],min(f[1],f[2]))+1,nf[1]=nf[2]=n+1;
        else if(x==1)nf[0]=min(f[0],min(f[1],f[2]))+1,nf[1]=n+1,nf[2]=min(f[0],f[1]);
        else if(x==2)nf[0]=min(f[0],min(f[1],f[2]))+1,nf[1]=min(f[0],f[2]),nf[2]=n+1;
        else nf[0]=min(f[0],min(f[1],f[2]))+1,nf[1]=min(f[0],f[2]),nf[2]=min(f[0],f[1]);
        for(int j=0;j<3;j++)f[j]=nf[j];
    }
    printf("%d\n",min(f[0],min(f[1],f[2])));
    return 0;
}