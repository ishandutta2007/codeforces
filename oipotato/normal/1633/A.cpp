#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
void get(int x,int&n,int a[])
{
    n=0;
    for(;x;a[++n]=x%10,x/=10);
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        int n1,n2,a1[10],a2[10];
        get(n,n1,a1);
        int ans=n1+1,way;
        for(int i=14;i<=999;i+=7)
        {
            get(i,n2,a2);
            if(n2==n1)
            {
                int tans=0;
                rep(j,n1)if(a1[j]!=a2[j])tans++;
                if(tans<ans)ans=tans,way=i;
            }
        }
        printf("%d\n",way);
    }
    return 0;
}