#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
bool vis[310];
int main()
{
	int n,x=0,y=0,z=0;
	scanf("%d",&n);
	rep(i,n)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		x+=a;y+=b;z+=c;
	}
	puts(x==0&&y==0&&z==0?"YES":"NO");
	return 0;
}