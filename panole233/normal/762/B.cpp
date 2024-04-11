#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a,b,c,m,v,ans;
long long val,usb[300001],ps[300001],s1[300001],s2[300001],x[300001];
char s[11];

int main()
{
	scanf("%d%d%d",&a,&b,&c);	
	scanf("%d",&m);
	memset(usb,0,sizeof(usb));
	memset(ps,0,sizeof(ps));
	for (int i=1; i<=m; i++)
	{
		scanf("%d%s",&v,&s);
		if (s[0]=='U') usb[++usb[0]]=v; else ps[++ps[0]]=v;
	}
	sort(usb+1,usb+1+usb[0]); sort(ps+1,ps+1+ps[0]);
	s1[1]=usb[1]; s2[1]=ps[1];
	memset(x,0,sizeof(x));
	for (int i=2; i<=usb[0]; i++) s1[i]=s1[i-1]+usb[i];
	for (int i=2; i<=ps[0]; i++) s2[i]=s2[i-1]+ps[i];
	if (a>usb[0]) ans+=usb[0],val+=s1[usb[0]]; else 
	{
		ans+=a,val+=s1[a];
		for (int i=a+1; i<=usb[0]; i++) x[++x[0]]=usb[i];
	}
	if (b>ps[0]) ans+=ps[0],val+=s2[ps[0]]; else
	{
		ans+=b,val+=s2[b];
		for (int i=b+1; i<=ps[0]; i++) x[++x[0]]=ps[i];
	}
	sort(x+1,x+1+x[0]);
	if (c>x[0])
	{
		ans+=x[0];
		for (int i=1; i<=x[0]; i++) val+=x[i]; 
	}else
	{
		ans+=c;
		for (int i=1; i<=c; i++) val+=x[i];
	}
	printf("%d %I64d\n",ans,val);
	return 0;
}