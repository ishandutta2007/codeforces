#include<cstdio>
#include<cstring>

long long n,a[200001],l,r,mid,ans,d[200001],s;
bool bo;

int read()
{
	int pjy=0,flag=1; char ch=getchar();
	while (ch>'9'||ch<'0') {if (ch=='-') flag=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') pjy=pjy*10+ch-48,ch=getchar();
	return pjy*flag;
}

int main()
{
	scanf("%I64d",&n); bo=1;
	for (int i=1; i<=n; i++)
	{
		a[i]=read(); d[i]=read();
		if (d[i]==2) bo=0;
	}
	if (bo) {printf("Infinity"); return 0;}
	l=-(2e9); r=2e9; ans=-(2e9)-1;
	while (l<=r)
	{
		mid=(l+r)>>1; s=mid; bo=1;
		for (int i=1; i<=n; i++)
		{ 
			if (d[i]==1&&s<1900) {l=mid+1; bo=0; break;}
			if (d[i]==2&&s>=1900) {r=mid-1; bo=0; break;}
			s+=a[i];
		}
		if (bo) ans=s,l=mid+1;
	}
	if (ans!=-(2e9)-1) printf("%I64d",ans); else printf("Impossible");
	return 0;
}