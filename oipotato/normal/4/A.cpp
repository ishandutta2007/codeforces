#include<cstdio>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	int x;
	scanf("%d",&x);
	if(x==2||(x&1))puts("NO");else puts("YES");
	return 0;
}