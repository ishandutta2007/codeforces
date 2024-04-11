#include<bits/stdc++.h>
using namespace std;

int n,p[200010],a[200010],nxt[200010],pre[200010];

void del(int p)
{
	nxt[pre[p]]=nxt[p];
	pre[nxt[p]]=pre[p];
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=2*n; i++)
	{
		nxt[i]=i+1,pre[i]=i-1;
		char ch=getchar();
		while (ch!='+'&&ch!='-') ch=getchar();
		if (ch=='-') scanf("%d",&a[i]),p[a[i]]=i;
		else a[i]=0;
	}
	a[0]=n+1;
	for (int i=1; i<=n; i++)
	{
		int x=pre[p[i]];
		if (a[x]) return puts("NO"),0;
		a[x]=-i,del(x),del(p[i]);
	}
	puts("YES");
	for (int i=1; i<=2*n ; i++) 
		if (a[i]<0) printf("%d ",-a[i]);
	puts("");
	return 0;
}