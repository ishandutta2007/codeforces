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
        puts("2");
        if(n==2)puts("1 2");
        else if(n==3)puts("1 3\n2 2");
        else
        {
            printf("%d %d\n",n,n-2);
            printf("%d %d\n",n-1,n-1);
            n--;
            for(;n-2>=1;n--)printf("%d %d\n",n,n-2);
        }
    }
    return 0;
}