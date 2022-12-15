#include<cstdio>
#include<cstring>

int n,k,stack[300001],top,x,ans;
char s[11];

int main()
{
	scanf("%d",&n); top=0; k=1;
	for (int i=1; i<=2*n; i++)
	{
		scanf("%s",&s);
		if (s[0]=='a') scanf("%d",&x),stack[++top]=x;
		else
		{
			if (top>0&&stack[top]!=k) {top=0; ans++;}
			else if (top>0) top--;
			k++;
		}
	}
	printf("%d",ans);
	return 0;
}