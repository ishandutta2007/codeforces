#include<cstdio>
#include<cstring>

int T,n,ans[13],s;

int main()
{
	ans[0]=ans[1]=ans[2]=ans[3]=ans[5]=ans[7]=ans[11]=-1;
	ans[4]=ans[6]=ans[9]=1; ans[8]=ans[10]=2; ans[12]=3;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n<13) {printf("%d\n",ans[n]); continue;}
		if (n&1) n-=9,s=1; else s=0;
		n>>=1; if (n&1) n-=3,s++;
		s+=(n>>1); printf("%d\n",s);
	}
	return 0;
}