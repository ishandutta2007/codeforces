#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int w[100010];
char s[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,x;
		scanf("%s",s+1);n=strlen(s+1);
		scanf("%d",&x);
		rep(i,n)w[i]=-1;
		rep(i,n)if(s[i]=='0'){if(i>x)w[i-x]=0;if(i+x<=n)w[i+x]=0;}
		bool ok=1;
		rep(i,n)if(s[i]=='1')
		{
			bool flag=0;
			if(i>x&&w[i-x])w[i-x]=1,flag=1;
			if(i+x<=n&&w[i+x])w[i+x]=1,flag=1;
			if(!flag){ok=0;break;}
		}
		if(!ok)puts("-1");else{rep(i,n)printf("%d",w[i]?1:0);puts("");}
	}
    return 0;
}