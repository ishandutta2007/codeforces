#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
const int N=1000210;
int sa[2][N],ranks[2][N];
char a[N];
char b[N];
int s[210],n,i,p=0,q=1,k=1;
int v[N],height[N],slen[210];
int st[N][21];
int rmq(int i,int j)
{
    int k=(int)(log(j-i+1.5)/log(2));
    return min(st[i][k],st[j-(1<<k)+1][k]);
}
int get(int sa[N],int rank[N],int SA[N],int RANK[N])
{
    for(i=1;i<=n;i++)
        v[rank[sa[i]]]=i;
    for(i=n;i>=1;i--)
        if(sa[i]>k)
            SA[v[rank[sa[i]-k]]--]=sa[i]-k;
    for(i=n-k+1;i<=n;i++)
        SA[v[rank[i]]--]=i;
    for(i=1;i<=n;i++)
        RANK[SA[i]]=RANK[SA[i-1]]+(rank[SA[i-1]]!=rank[SA[i]]||rank[SA[i-1]+k]!=rank[SA[i]+k]);
}
int getheight()
{
    for(int i=1,j=0;i<=n;i++)
    {
        if(ranks[p][i]==1)
            continue;
        while(a[i+j]==a[sa[p][ranks[p][i]-1]+j])
            j++;
        height[ranks[p][i]]=j;
        if(j>0)
            j--;
    }
}
int ans[210];
int dp[5010][5010],pre[5010][5010],lz[5010];
const int mod=inf+7;
int main()
{
    cin>>n;
    scanf("%s",a+1);
    for(i=1;i<=n;i++)
        v[a[i]]++;
    for(i=1;i<=256;i++)
        v[i]+=v[i-1];
    for(i=1;i<=n;i++)
        sa[p][v[a[i]]--]=i;
    for(i=1;i<=n;i++)
        ranks[p][sa[p][i]]=ranks[p][sa[p][i-1]]+(a[sa[p][i-1]]!=a[sa[p][i]]);
    while(k<=n)
    {
        get(sa[p],ranks[p],sa[q],ranks[q]);
        swap(p,q);
        k=k<<1;
    }
//  for(int i=1;i<=n;i++)
//      cout<<sa[p][i]<<' '<<ranks[p][i]<<endl;
    getheight();
    int n1,n2;
    for(n1=1;n1<=n;n1++)
        st[n1][0]=height[n1];
    int d=(int)(log(n+0.5)/log(2));
    for(n2=1;n2<=d;n2++)
        for(n1=1;n1+(1<<n2)-1<=n;n1++)
            st[n1][n2]=min(st[n1][n2-1],st[n1+(1<<(n2-1))][n2-1]);
    for(int i=1;i<=n;i++)
        dp[1][i]=pre[1][i]=1;
    for(int i=1;i<=n;i++)
        lz[i]=(int)(log(i+0.5)/log(2.0));
    for(int j=2;j<=n;j++)
        for(int k=2;k<=j;k++)
        {
            if(a[k]=='0')
            {
                dp[k][j]=0;
                pre[k][j]=(pre[k-1][j]+dp[k][j])%mod;
                continue;
            }
            int x=k-1-(j-k);
            if(x<=0)
            {
                dp[k][j]=pre[k-1][k-1];
            }
            else
            {
                int y=ranks[p][x],z=ranks[p][k];
        //      cout<<y<<' '<<z<<endl;
                if(y>z)
                {
                    dp[k][j]=(pre[k-1][k-1]-pre[x][k-1]+mod)%mod;
                    pre[k][j]=(pre[k-1][j]+dp[k][j])%mod;
                    continue;
                }
                int a=lz[z-y];
                int p=min(st[y+1][a],st[z-(1<<a)+1][a]);
            //  cout<<k<<' '<<j<<' '<<' '<<x<<' '<<y<<' '<<z<<' '<<p<<' '<<a<<' '<<st[3][0]<<endl;
                if(p>=(j-k+1)||y>z)
                    dp[k][j]=(pre[k-1][k-1]-pre[x][k-1]+mod)%mod;
                else
                    dp[k][j]=(pre[k-1][k-1]-pre[x-1][k-1]+mod)%mod;
            }
            pre[k][j]=(pre[k-1][j]+dp[k][j])%mod;
        //  cout<<k<<' '<<j<<' '<<dp[k][j]<<endl;
        }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[i][n])%mod;
    cout<<ans;          
}