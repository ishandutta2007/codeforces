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
        int n;
        scanf("%d",&n);
        int last=(int)1e9+1;
        bool flag=1;
        rep(i,n)
        {
            int x;scanf("%d",&x);
            if(x>=last)flag=0;
            last=x;
        }
        puts(flag?"NO":"YES");
    }
    return 0;
}