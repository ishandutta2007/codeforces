#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;
int p[MAXN],s[MAXN];
int q[MAXN],r[MAXN];
int ansl[MAXN*MAXN],ansr[MAXN*MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(int i=1;i<=n;i++)
        q[s[i]]=i;
    for(int i=1;i<=n;i++)
        p[i]=q[p[i]];
    for(int i=1;i<=n;i++)
        r[p[i]]=i;
    ll ans=0;
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        while(r[i]<i)
        {
            for(int j=r[i]+1;j<=i;j++)
            {
                if(p[j]<=r[i])
                {
                    ansl[cnt]=r[i];
                    ansr[cnt++]=j;
                    ans+=j-r[i];
                    swap(r[i],r[p[j]]);
                    swap(p[r[i]],p[r[p[j]]]);
                    break;
                }
            }
        }
    }
    printf("%I64d\n",ans);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf("%d %d\n",ansl[i],ansr[i]);
    return 0;
}