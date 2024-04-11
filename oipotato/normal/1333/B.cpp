#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[100010],b[100010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        rep(i,n)scanf("%d",&b[i]);
        bool flag[2]={0,0};
        bool ans=1;
        rep(i,n)
        {
            if(a[i]!=b[i])
            {
                bool need=a[i]<b[i];
                if(!flag[need])ans=0;
            }
            if(a[i])flag[a[i]>0]=1;
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}