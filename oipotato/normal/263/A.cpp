#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	rep(i,5)rep(j,5)
	{
		int x;
		scanf("%d",&x);
		if(x){printf("%d\n",abs(i-3)+abs(j-3));return 0;}
	}
	return 0;
}