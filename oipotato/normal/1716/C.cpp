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
typedef unsigned long long ULL;
typedef long double LD;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,a[3][200010],suf1[3][200010],suf2[3][200010];
		scanf("%d",&n);
		rep(i,2)rep(j,n){scanf("%d",&a[i][j]);if(a[i][j])a[i][j]++;}
		rep(i,2)suf1[i][n+1]=suf2[i][n+1]=-(int)2e9;
		rep(i,2)for(int j=n;j;j--)suf1[i][j]=max(suf1[i][j+1],a[i][j]-j),suf2[i][j]=max(suf2[i][j+1],a[i][j]-(n-j));
		int ans=max(suf1[1][1]+1,suf2[2][1]-n),now=-(int)2e9;
		rep(i,n-1)
		{
			int l=1,r=2;if(i&1)swap(l,r);
			now=max(now,max(a[r][i]-(2*i-2),a[l][i]-(2*i-1)));
			ans=min(ans,max(now,max(suf1[l][i+1]+i-(2*i-1),suf2[r][i+1]-(n+i))));
		}
		printf("%d\n",ans+2*n-1);
	}
    return 0;
}