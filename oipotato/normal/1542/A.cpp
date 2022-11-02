#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n;
		scanf("%d",&n);
		int a=0,b=0;
		rep(i,2*n)
		{
			int x;scanf("%d",&x);
			if(x&1)a++;else b++;
		}
		puts(a==b?"Yes":"No");
	}
    return 0;
}