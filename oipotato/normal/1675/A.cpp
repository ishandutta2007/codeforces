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
        int a,b,c,x,y;scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
        puts(max(0,x-a)+max(0,y-b)<=c?"YES":"NO");
    }
    return 0;
}