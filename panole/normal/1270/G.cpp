#include<bits/stdc++.h>
using namespace std;

bool bo[1000010];
int n,T,a[1000010],ans[1000010],ansn,p;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]),bo[i]=0,a[i]=i-a[i];
		ans[ansn=1]=1;
		while (!bo[ans[ansn]])
		{
			bo[ans[ansn]]=1;
			ans[ansn+1]=a[ans[ansn]];
			ansn++;
		}
		for (int i=ansn-1; i; i--)
			if (ans[i]==ans[ansn]) {p=i; break;}
		printf("%d\n",ansn-p);
		for (int i=p+1; i<=ansn; i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}