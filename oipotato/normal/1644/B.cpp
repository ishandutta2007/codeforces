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
        int n;scanf("%d",&n);
        rep(i,n)
        rep(j,n)
        {
            int x=i;
            if(j!=1)x=n-j+2>i?n-j+2:n-j+1;
            printf("%d%c",x," \n"[j==n]);
        }
    }
    return 0;
}