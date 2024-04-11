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
        int n,p[210];scanf("%d",&n);
        rep(i,n)scanf("%d",&p[i]);
        rep(i,n)
        {
            int ans=1;
            for(int j=i;p[j]!=i;j=p[j],ans++);
            printf("%d%c",ans," \n"[i==n]);
        }
    }
    return 0;
}