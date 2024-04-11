#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	rep(i,n)
	{
		int cnt=0;
		rep(j,3){int x;scanf("%d",&x);cnt+=x;}
		if(cnt>=2)ans++;
	}
	printf("%d\n",ans);
	return 0;
}