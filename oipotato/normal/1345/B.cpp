#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=26000;
int f[N+10];
int main()
{
	f[0]=0;
	rep(i,N)f[i]=f[i-1]+i-1+2*i;
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		int ans=0;
		for(int i=N;i;i--)ans+=n/f[i],n%=f[i];
		printf("%d\n",ans);
	}
    return 0;
}