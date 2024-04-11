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
    int n;
    long long m;
    scanf("%d%lld",&n,&m);
    printf("%lld ",max(0ll,n-m*2));
    if(m==0){printf("%d\n",n);return 0;}
    rep(i,n)if(1ll*i*(i-1)/2>=m){printf("%d\n",n-i);return 0;}
	return 0;
}