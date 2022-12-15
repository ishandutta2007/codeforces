#include<cstdio>
#include<cstring>

int t[20],n,ans[1000001],shi[10],x,xx;

int main()
{
	scanf("%d",&n); ans[0]=0;
	shi[0]=1;
	for (int i=1; i<=9; i++) shi[i]=shi[i-1]*10;
	for (int j=1; j<=81; j++)
	{
		x=n-j;
		t[0]=0;
		while (x) t[++t[0]]=x%10,x/=10;
		xx=0;
		for (int k=1; k<=t[0]; k++) xx+=t[k];
		if (xx==j) ans[++ans[0]]=n-j;
	}
	printf("%d\n",ans[0]);
	for (int i=ans[0]; i>=1; i--) printf("%d ",ans[i]);
	return 0;
}