#include <bits/stdc++.h>
#define MAXN 200007
#define MAXL 30
using namespace std;
int a[MAXN],cnt[MAXL];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n; scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int j=0;j<MAXL;j++) cnt[j]=0;
        for(int j=0;j<MAXL;j++) for(int i=0;i<n;i++) if(a[i]&(1<<j)) cnt[j]++;
        for(int i=1;i<=n;i++)
        {
            bool ok=true;
            for(int j=0;j<MAXL;j++) if(cnt[j]%i!=0) ok=false;
            if(ok) printf("%d ",i);
        }
        printf("\n");
    }
}