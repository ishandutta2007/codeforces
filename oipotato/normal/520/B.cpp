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
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=n+15+(1<<15)-m,cnt=0;
	for(;n<m;)
	{
		int tmp=n,cc=0;
		for(;tmp<m;tmp*=2,cc++);
		ans=min(ans,cnt+cc+tmp-m);
		if(m&1)m++,cnt++;
		m/=2;cnt++;
	}
	ans=min(ans,cnt+n-m);
	printf("%d\n",ans);
    return 0;
}