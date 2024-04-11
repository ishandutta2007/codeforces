#include<bits/stdc++.h>
using namespace std;

int n,a[200010],cnt,b[200010];
char s[200010];

bool check()
{
	int nw=0;
	for (int i=1; i<=n; i++)
		if (b[i]==0) nw++;
		else
		{
			nw--;
			if (nw<0) return 0;
		}
	return 1;
}

int main()
{
	scanf("%d%s",&n,s);
	for (int i=0; i<n; i++) cnt+=(a[i+1]=(s[i]==')'));
	if ((n&1)||cnt!=n/2) return puts("No"),0;
	for (int i=1; i<=n; i++) if (a[i]==0) cnt=i;
	b[1]=0;
	for (int i=2; i<=cnt; i++) b[i]=a[i-1];
	for (int i=cnt+1; i<=n; i++) b[i]=a[i];
	if (check()) return puts("Yes"),0;
	for (int i=n; i; i--) if (a[i]==1) cnt=i;
	b[n]=1;
	for (int i=1; i<cnt; i++) b[i]=a[i];
	for (int i=cnt+1; i<=n; i++) b[i-1]=a[i];
	if (check()) return puts("Yes"),0;
	puts("No");
	return 0;
}