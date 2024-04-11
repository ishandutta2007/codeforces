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
        int n,p[510];scanf("%d",&n);
        rep(i,n)scanf("%d",&p[i]);
        int aim=-1;
        rep(i,n)if(p[i]!=i){aim=i;break;}
        if(aim!=-1)rep(i,n)if(p[i]==aim){reverse(p+aim,p+i+1);break;}
        rep(i,n)printf("%d%c",p[i]," \n"[i==n]);
    }
    return 0;
}