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
    // for(scanf("%d",&T);T--;)
    {
        int a,b,s;scanf("%d%d%d",&a,&b,&s);
        a=abs(a)+abs(b);
        if(s<a||(s-a)%2==1)puts("No");else puts("Yes");
    }
    return 0;
}