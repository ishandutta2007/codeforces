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
        int n,pos=-1;
        scanf("%d",&n);
        rep(i,n)
        {
            int x;scanf("%d",&x);
            if(!(x&1))pos=i;
        }
        if(pos!=-1)printf("1\n%d\n",pos);
        else if(n!=1)printf("2\n1 2\n");
        else printf("-1\n");
    }
    return 0;
}