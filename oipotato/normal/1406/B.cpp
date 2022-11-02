#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int a[100010],b[100010],c[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		int c1=0,c2=0;
		rep(i,n)
		{
			int x;scanf("%d",&x);
			if(x<0)a[++c1]=x;else b[++c2]=x;
			c[i]=x;
		}
		sort(c+1,c+n+1,[&](int x,int y){return abs(x)<abs(y);});
		sort(a+1,a+c1+1);
		sort(b+1,b+c2+1,greater<int>());
		LL ans=(LL)c[1]*c[2]*c[3]*c[4]*c[5];
		if(c2>=5)ans=(LL)b[1]*b[2]*b[3]*b[4]*b[5];
		if(c2>=3&&c1>=2)ans=max(ans,(LL)b[1]*b[2]*b[3]*a[1]*a[2]);
		if(c2>=1&&c1>=4)ans=max(ans,(LL)b[1]*a[1]*a[2]*a[3]*a[4]);
		if(c1+c2<n)ans=max(ans,0ll);
		printf("%lld\n",ans);
	}
    return 0;
}