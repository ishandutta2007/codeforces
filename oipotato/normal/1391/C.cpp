#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int MOD=(int)1e9+7;
int main()
{
	int n;
	scanf("%d",&n);
	int a=1,b=1;
	rep(i,n)a=1ll*a*i%MOD;
	rep(i,n-1)b=(b<<1)%MOD;
	printf("%d\n",(a-b+MOD)%MOD);
	return 0;
}