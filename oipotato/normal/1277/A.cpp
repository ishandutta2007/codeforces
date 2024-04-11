#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int T,n;
int main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&n);
		int ans=0;
		rep(i,9)
		rep(j,9)
		{
			int x=0;
			rep(k,i)x=x*10+j;
			if(x<=n)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}