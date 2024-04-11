#include<bits/stdc++.h>
using namespace std;

long long Ans;
int n,a[100010],b[100010],ansn,ans[100010][2],sa,sb,len0,len9;
char s[100010];

void add(int x,int fl)
{
	if (ansn>=100000) return;
	ans[++ansn][0]=x,ans[ansn][1]=((x&1)*2-1)*fl;
}

int main()
{
	scanf("%d",&n),scanf("%s",s);
	for (int i=1; i<=n; i++) a[i]=s[i-1]-'0';
	scanf("%s",s),ansn=sa=sb=0,Ans=0;
	for (int i=1; i<=n; i++) b[i]=s[i-1]-'0';
	for (int i=2; i<=n; i+=2) a[i]=9-a[i],b[i]=9-b[i];
	for (int i=1; i<=n; i++) sa+=a[i],sb+=b[i];
	if (sa!=sb) return puts("-1"),0;
	len0=len9=n;
	for (int i=1; i<=n; i++) if (a[i]!=0) {len0=i-1; break;}
	for (int i=1; i<=n; i++) if (a[i]!=9) {len9=i-1; break;}
	for (int i=1; i<n; i++)
	{
		if (a[i]==0) len0--;
		if (a[i]==9) len9--; 
		while (i+1+len0<=n&&a[i+1+len0]==0) len0++;
		while (i+1+len9<=n&&a[i+1+len9]==9) len9++;
		while (a[i]>b[i])
		{
			if (a[i+1+len9]==0) len0=0;
			a[i+1+len9]++,a[i]--;
			if (ansn<100000) for (int k=i+len9; k>=i; k--) add(k,-1);
			Ans+=(len9+1);
			while (i+1+len9<=n&&a[i+1+len9]==9) len9++;
		}
		while (a[i]<b[i])
		{
			if (a[i+1+len0]==9) len9=0;
			a[i+1+len0]--,a[i]++;
			if (ansn<100000) for (int k=i+len0; k>=i; k--) add(k,1);
			Ans+=(len0+1);
			while (i+1+len0<=n&&a[i+1+len0]==0) len0++;
		}
	}
	printf("%I64d\n",Ans);
	for (int i=1; i<=ansn; i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}