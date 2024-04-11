#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[1010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        bool flag=1;
        a[1]=1;
        for(int i=2;i<=n;i++)if((LL)a[i-1]*3<=(int)1e9)a[i]=a[i-1]*3;else{flag=0;break;}
        if(!flag)puts("NO");
        else
        {
            puts("YES");
            rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}