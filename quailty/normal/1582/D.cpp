#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
pair<int,int> a[MAXN];
int b[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i].first),a[i].second=i;
    sort(a,a+n);
    for(int i=(n%2 ? 3 : 0);i<n;i+=2)
    {
        int g=__gcd(a[i].first,a[i+1].first);
        b[a[i].second]=-a[i+1].first/g;
        b[a[i+1].second]=a[i].first/g;
    }
    if(n&1)
    {
        int res[3]={0,0,0};
        int val[3]={a[0].first,a[1].first,a[2].first};
        for(int x=-1;x<=1;x++)
        for(int y=-1;y<=1;y++)
        for(int z=-1;z<=1;z++)
        {
            int tmp[3];
            tmp[0]=val[1]*z-val[2]*y;
            tmp[1]=val[2]*x-val[0]*z;
            tmp[2]=val[0]*y-val[1]*x;
            if(tmp[0] && tmp[1] && tmp[2])
                res[0]=tmp[0],res[1]=tmp[1],res[2]=tmp[2];
        }
        for(int i=0;i<3;i++)
            b[a[i].second]=res[i];
    }
    for(int i=0;i<n;i++)
        printf("%d%c",b[i]," \n"[i==n-1]);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}