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
        int l1,l2,r1,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(l1<=r2&&l2<=r1)printf("%d\n",max(l1,l2));
        else printf("%d\n",l1+l2);
    }
    return 0;
}