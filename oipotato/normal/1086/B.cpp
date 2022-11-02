#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int in[100010],ans,n,s;
int main()
{
	scanf("%d%d",&n,&s);
	rep(i,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		in[x]++;
		in[y]++;
	}
	rep(i,n)if(in[i]==1)ans++;
	printf("%.10lf\n",2.0*s/ans);
	return 0;
}