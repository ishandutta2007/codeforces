#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int num0[500010],num1[500010];
char s[500010];
int cnt,n,ans;
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%s",s);
		int len=strlen(s);
		int x=0,mi=0;
		for(int j=0;j<len;j++)
		{
			if(s[j]=='(')x++;else x--;
			mi=min(mi,x);
		}
		if(x>0&&mi>=0)num0[x]++;
		else if(x==0&&mi==0)cnt++;
		else if(x<0&&mi>=x)num1[-x]++;
	}
	rep(i,500000)ans+=min(num0[i],num1[i]);
	ans+=cnt/2;
	printf("%d\n",ans);
	return 0;
}