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
        int a,b;scanf("%d%d",&a,&b);
        if(a<b)swap(a,b);
        a=min(1ll*a,3ll*b);
        printf("%d\n",(a+b)/4);
    }
    return 0;
}