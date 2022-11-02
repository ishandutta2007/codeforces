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
        int n,a[100010];scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        int pos=1;
        rep(i,n)if(a[i]<a[pos])pos=i;
        printf("%d\n",n-(pos==1));
        if(pos!=1)printf("%d %d %d %d\n",1,pos,a[pos],a[1]),swap(a[1],a[pos]);
        for(int i=2;i<=n;i++)printf("%d %d %d %d\n",1,i,a[1],a[1]+i-1);
    }
    return 0;
}