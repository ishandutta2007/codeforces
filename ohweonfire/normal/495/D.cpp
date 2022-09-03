#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100005;
const int mod=1000000007;
char a[maxn],b[maxn];
int next[maxn],last,n,m,g[maxn],pg[maxn],ppg[maxn];
int main()
{
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    int j=0;
    next[1]=0;
    for(int i=2;i<=m;i++)
    {
        while(j>0&&b[j+1]!=b[i])
            j=next[j];
        if(b[j+1]==b[i])
            j++;
        next[i]=j;
    }
    j=0;
    for(int i=1;i<=n;i++)
    {
        while(j>0&&a[i]!=b[j+1])
            j=next[j];
        if(b[j+1]==a[i])
            j++;
        if(j==m)
        {
            j=next[j];
            last=i;
        }
        if(last)g[i]=(ppg[last-m]+last-m+1)%mod;
        pg[i]=(pg[i-1]+g[i])%mod;
        ppg[i]=(ppg[i-1]+pg[i])%mod;
    }
    int ans=0;
    printf("%d\n",pg[n]);
    return 0;
}