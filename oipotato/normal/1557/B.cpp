#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010],b[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k;scanf("%d%d",&n,&k);
        rep(i,n)scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+n+1);
        rep(i,n)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
        int num=0;
        rep(i,n)
        {
            int j=i;num++;
            for(;j<n&&a[j+1]==a[j]+1;j++);
            i=j;
        }
        puts(num<=k?"Yes":"No");
    }
    return 0;
}