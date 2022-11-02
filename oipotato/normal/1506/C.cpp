#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,m;
char a[25],b[25];
int cal()
{
    for(int i=min(n,m);i;i--)
    rep(j,n-i+1)
    rep(k,m-i+1)
    {
        bool flag=1;
        rep(p,i)if(a[j+p-1]!=b[k+p-1]){flag=0;break;}
        if(flag)return i;
    }
    return 0;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s%s",a+1,b+1);
        n=strlen(a+1);m=strlen(b+1);
        printf("%d\n",n+m-2*cal());
    }
    return 0;
}