#include<bits/stdc++.h>
using namespace std;

int n,a[400010],I,p[400010],pn,ans;

int main()
{
	scanf("%d%d",&n,&I),I*=8,I/=n;
	if (I>=20) return puts("0"),0;
	I=(1<<I);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);int nw=0; pn=0;
	for (int i=1; i<=n; i++)
		if (i!=1&&a[i]==a[i-1]) nw++;
		else 
		{
			if (nw) p[++pn]=nw;
			nw=1;
		}
	if (nw) p[++pn]=nw;
	if (I>=pn) return puts("0"),0;
	nw=0,ans=n;
	for (int i=1; i<=I; i++) nw+=p[i];
	ans=min(ans,n-nw);
	for (int i=I+1; i<=pn; i++) nw+=p[i]-p[i-I],ans=min(ans,n-nw);
	printf("%d\n",ans);
	return 0;
}