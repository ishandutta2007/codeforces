#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
int main()
{
    int T;scanf("%d",&T);
    for(;T--;)
    {
        int s,a,b,c;
        scanf("%d%d%d%d",&s,&a,&b,&c);
        int x=s/c/a;
        printf("%lld\n",s/c+1ll*x*b);
    }
	return 0;
}