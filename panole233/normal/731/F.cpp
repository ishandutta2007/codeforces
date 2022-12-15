#include<cstdio>
#include<cstring>

long long ans[200002],s[400002],anss[200001],max;
int n,x,a[200001];

int read() 
{
	int pjy=0; char ch=getchar(); 
	while (ch<'0'||ch>'9') ch=getchar(); 
	while (ch>='0'&&ch<='9') pjy=pjy*10+ch-48,ch=getchar(); 
	return pjy;
}

int main()
{
	n=read();
	memset(s,0,sizeof(s));
	for (int i=1; i<=n; i++) a[i]=read(),s[a[i]]++;
	for (int i=200000; i>=1; i--) s[i]+=s[i+1],ans[i]=(s[i]-s[i*2])*i;
	for (int i=100000; i>=1; i--)
		for (int j=2; j<=200000/i; j++) ans[i]+=(s[i*j]-s[i*(j+1)])*(i*j);
	max=0;
	for (int i=1; i<=n; i++) 
		if (ans[a[i]]>max) max=ans[a[i]];
	printf("%I64d",max);
	return 0;
}