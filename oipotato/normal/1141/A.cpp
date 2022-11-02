#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    if(m%n)puts("-1");
    else
    {
        m/=n;
        int x=0;
        for(;m%2==0;m/=2,x++);
        for(;m%3==0;m/=3,x++);
        printf("%d\n",m==1?x:-1);
    }
    return 0;
}