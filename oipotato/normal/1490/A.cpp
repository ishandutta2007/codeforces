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
int a[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		int ans=0;
		rep(i,n-1)
		{
			int x=a[i],y=a[i+1];
			if(x>y)swap(x,y);
			for(int j=2*x;j<y;ans++,j*=2);
		}
		printf("%d\n",ans);
	}
    return 0;
}