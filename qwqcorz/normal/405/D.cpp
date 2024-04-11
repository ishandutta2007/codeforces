#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+1e3;
const bool CWT_AK_IOI=1;

ll read()
{
    ll s=0;
    char c=getchar();
    while (c<'0'||'9'<c) c=getchar();
    while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
    return s;
}
void write(ll n)
{
    if (n<0)
    {
        putchar('-');
        n=abs(n);
    }
    if (n<10)
    {
        putchar(n+'0');
        return;
    }
    write(n/10);
    putchar(n%10+'0');
}
ll n,m=1e6,sum=0,a[N],b[N],cnt=0;
bool can[N];

int main()
{
    memset(can,1,sizeof(can));
    scanf("%lld",&n);
    for (int i=1;i<=n;i++)
    {
        ll x=read();
        can[x]=0;
        sum+=x-1;
    }
    for (int i=1;i<=m;i++) if (can[i]) a[++cnt]=m-i;
    while (CWT_AK_IOI)
    {
        ll now=0,ans=0;
        random_shuffle(a+1,a+1+n);
        for (int i=1;i<=cnt;i++)
        if (now+a[i]<=sum)
        {
            b[++ans]=m-a[i];
            now+=a[i];
            if (now==sum)
            {
                write(ans);
                putchar('\n');
                for (int j=1;j<=ans;j++)
                {
                    write(b[j]);
                    putchar(' ');
                }
                return 0;
            }
        }
    }
    return -2333;
}