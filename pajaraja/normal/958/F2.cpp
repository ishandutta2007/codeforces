#include <bits/stdc++.h>
using namespace std;
int a[200007],c[200007];
bool u[200007];
int main()
{
	int n,m,td=0,br=0,sol=2000020;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) a[i]--;
	for(int i=0;i<m;i++) scanf("%d",&c[i]);
	for(int i=0;i<m;i++) td+=c[i];
	for(int i=0;i<m;i++) if(c[i]==0) {u[i]=true; br++;}
	int t1=0,t2=-1;
	while(t2<n)
	{
		if(br==m)
		{
			sol=fmin(sol,t2-t1+1-td);
			c[a[t1]]++;
			if(c[a[t1]]>0) {br--; u[a[t1]]=false;}
			t1++;
		}
		else
		{
			t2++;
			if(c[a[t2]]==1) {br++; u[a[t2]]=true;}
			c[a[t2]]--;
		}
	}
	if(sol==2000020) sol=-1;
	printf("%d",sol);
}