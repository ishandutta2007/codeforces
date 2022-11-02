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
    long long l,r;
    scanf("%lld%lld",&l,&r);
    puts("YES");
    for(;l<=r;l+=2)printf("%lld %lld\n",l,l+1);
	return 0;
}