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
        int n;scanf("%d",&n);
        if(n%3==2)printf("1 2 %d\n",n-3);
        else printf("1 1 %d\n",n-2);
    }
    return 0;
}