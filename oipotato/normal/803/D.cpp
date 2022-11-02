#include<cstdio>
#include<cstring>
using namespace std;
int k,len,tans,tk,tlen,n,a[1000010];
char s[1000010];
bool check(int x)
{
	tans=0;
	tk=k;
	for(int i=1;i<=n;i++)
	if(tans+a[i]>x)
	{
		if(a[i]>x)return 0;
		tans=a[i];
		tk--;
	}
	else tans+=a[i];
	return tk-1>=0;
}
int main()
{
	scanf("%d\n",&k);
	gets(s);
	len=strlen(s);
	for(int i=0;i<len;i++)
	if(s[i]=='-'||s[i]==' ')
	{
		a[++n]=++tlen;
		tlen=0;
	}
	else tlen++;
	a[++n]=tlen;
	int l=0,r=1000000;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%d",r);
	return 0;
}