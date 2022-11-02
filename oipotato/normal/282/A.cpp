#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	rep(i,n)
	{
		char s[10];
		scanf("%s",s);
		if(s[0]=='+')ans++;
		else if(s[0]=='-')ans--;
		else if(s[1]=='+')ans++;
		else ans--;
	}
	printf("%d\n",ans);
	return 0;
}