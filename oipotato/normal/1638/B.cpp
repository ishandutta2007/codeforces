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
        int n,n1=0,n2=0,a[100010],b[100010];scanf("%d",&n);
        rep(i,n){int x;scanf("%d",&x);if(x&1)a[++n1]=x;else b[++n2]=x;}
        bool flag=1;
        rep(i,n1-1)if(a[i]>a[i+1])flag=0;
        rep(i,n2-1)if(b[i]>b[i+1])flag=0;
        puts(flag?"Yes":"No");
    }
    return 0;
}