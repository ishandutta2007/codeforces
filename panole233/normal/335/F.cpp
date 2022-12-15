#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int h[500001],len,n,a[500001],nw,tot,tmp,cnt,t[500001];
long long ans;

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

bool cmp(int x,int y) {return x>y;}

void work(int x)
{
	int y=(x>>1);
	while (y&&h[y]>h[x])
	{
		tmp=h[x]; h[x]=h[y]; h[y]=tmp;
		x=y; y=(x>>1);
	}
}

void pop()
{
	h[1]=h[len--];
	int x=1,y=2;
	if (y<len&&h[y+1]<h[y]) y++;
	while (y<=len&&h[y]<h[x])
	{
		tmp=h[x]; h[x]=h[y]; h[y]=tmp;
		x=y; y=(x<<1);
		if (y<len&&h[y+1]<h[y]) y++;
	}
}

int main()
{
	n=read(); ans=0;
	for (int i=1; i<=n; i++) a[i]=read(),ans+=1ll*a[i];
	len=0; sort(a+1,a+1+n,cmp);
	nw=tot=cnt=0;
	for (int i=1; i<=n; i++)
	{
		if (!nw) nw=a[i],tot=1; else
		{
			if (nw>a[i]) 
			{
				tot--,t[++cnt]=a[i]; 
				if (!tot) nw=0;
			} else
			{
				tot++;
				if (tot>=2&&len&&h[1]<a[i]*2) 
				{
					if (h[1]<a[i]) t[++cnt]=a[i],t[++cnt]=a[i];
					else t[++cnt]=h[1],t[++cnt]=a[i]*2-h[1];
					pop(); tot-=2;
					if (!tot) nw=0;
				}
			}
		}
		if (i==n||a[i+1]!=a[i])
		{
			if (nw==a[i]&&len&&h[1]<a[i]) pop(),t[++cnt]=a[i];
			for (int j=1; j<=cnt; j++) h[++len]=t[j],work(len);
			cnt=0;
		}
	}
	for (int i=1; i<=len; i++) ans-=1ll*h[i];
	printf("%I64d\n",ans);
	return 0;
}