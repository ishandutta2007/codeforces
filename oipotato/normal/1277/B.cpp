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
set<int>s;
int main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&n);
		s.clear();
		rep(i,n)
		{
			int x;scanf("%d",&x);
			for(;!(x&1);s.insert(x),x/=2);
		}
		printf("%d\n",s.size());
	}
	return 0;
}