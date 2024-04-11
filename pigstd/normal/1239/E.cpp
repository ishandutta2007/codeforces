#include<bits/stdc++.h>
using namespace std;

const int N=53;
const int M=1250010;
int dp[N/2][M],ans[N][3],n,f[M],pre[N/2][M],a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void print(int x)
{
    int now=n-1;
    for (int i=1;i<=n-1;i++)
        ans[i][2]=pre[now][x],f[pre[now][x]]--,x-=pre[now][x],now--;
    int cnt=1;
    for (int i=0;i<M;i++)
        while(f[i])
            ans[++cnt][1]=i,f[i]--;
    for (int i=1;i<=n;i++)cout<<ans[i][1]<<' ';
    puts("");
    for (int i=1;i<=n;i++)cout<<ans[i][2]<<' ';
}

int main()
{
    n=read();int sum=0;
    for (int i=1;i<=2*n;i++)a[i]=read(),sum+=a[i];
    sort(a+1,a+1+n*2);dp[0][0]=1;
    ans[1][1]=a[1],ans[n][2]=a[2];sum-=a[1]+a[2];sum/=2;
    for (int i=3;i<=2*n;i++)f[a[i]]++;
    for (int i=3;i<=n*2;i++)
        for (int j=min(n-1,i);j>=1;j--)
            for (int k=sum;k>=a[i];k--)
            {
                if (dp[j][k])continue;
                if (dp[j-1][k-a[i]])
                    dp[j][k]=1,pre[j][k]=a[i];
            }
//    cout<<"miaomiaomiao"<<endl;;
//    return 0;
    for (int i=sum;i>=0;i--)
        if (dp[n-1][i])
            {print(i);break;}
    return 0;
}