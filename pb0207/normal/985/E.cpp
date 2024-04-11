#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],f[N],q[N],tail,head,k,d;

int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	head=1;
	for(int i=k;i<=n;i++)
	{
		if(f[i-k])
			q[++tail]=i-k+1;
		while(head<=tail&&a[i]-a[q[head]]>d)
			head++;
		f[i]=(head<=tail);
	} 
	puts(f[n]?"YES":"NO");
}