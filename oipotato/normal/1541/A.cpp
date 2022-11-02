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
int a[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i+=2)
		{
			if(i+2==n)a[i]=i+2,a[i+1]=i,a[i+2]=i+1,i++;
			else a[i]=i+1,a[i+1]=i;
		}
		rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
	}
    return 0;
}