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
        int n,x,a[110];scanf("%d%d",&n,&x);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        int sum=0;
        bool flag=1;
        rep(i,n)
        {
            sum+=a[i];
            if(sum==x)
            {
                if(a[1]==a[n]||i==n){flag=0;break;}
                int tmp=a[n];
                for(int j=n;j>i+1;j--)a[j]=a[j-1];
                a[i+1]=a[1];
                a[1]=tmp;
                break;
            }
        }
        if(!flag)puts("NO");
        else
        {
            puts("YES");
            rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}