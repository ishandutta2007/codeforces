#include <cstdio>
#include <cstring>
#include<cstdio>
#include<cstring>

const int N=100001;
bool b[N];
long long n,m,ans[N],X[N],Y[N];
int k,cnt1,cnt2,head1[N*2],head2[N*2];

struct xint{int to,next;}e1[N],e2[N];

int read()
{
	int pjy=0,flag=1; char ch;
	while (ch>'9'||ch<'0') {if (ch=='-') flag=-1; ch=getchar();}
	while (ch<='9'&&ch>='0') pjy=pjy*10+ch-48,ch=getchar();
	return pjy*flag;
}

void addedge1(int x,int y)
{
	e1[++cnt1].to=y;
	e1[cnt1].next=head1[x];
	head1[x]=cnt1;
}

void addedge2(int x,int y)
{
	e2[++cnt2].to=y;
	e2[cnt2].next=head2[x];
	head2[x]=cnt2;
}

long long abs(long long x){return x<0?-x:x;}

int main()
{
	n=read(),m=read(),k=read();
	for (int i=1 ;i<=k; i++)
	{
		int x=read(),y=read();
		addedge1(y-x+100000,i);
		addedge2(x+y,i);
		X[i]=x; Y[i]=y;
	}
	long long t=0,nowx=0,nowy=0;
	for (int i=1 ;i<=k; i++) ans[i]=-1;
	while(1)
	{
		for(int i=head1[nowy-nowx+100000];i;i=e1[i].next)
		{
			int pos=e1[i].to;
			if(b[pos])continue;b[pos]=1;
			ans[pos]=t+abs(X[pos]-nowx);
		}
		if(nowx==n||nowy==m){
			if(nowx<nowy){t+=nowx;nowy-=nowx;nowx=0;}else
			{t+=nowy;nowx-=nowy;nowy=0;}
		}else
		if(nowx==0||nowy==0){
			if(n-nowx<m-nowy){t+=n-nowx;nowy+=n-nowx;nowx=n;}else
			{t+=m-nowy;nowx+=m-nowy;nowy=m;}
		}
		if(nowx==n&&nowy==m)break;if(nowx==n&&nowy==0)break;if(nowx==0&&nowy==m)break;if(nowx==0&&nowy==0)break;
		for(int i=head2[nowy+nowx];i;i=e2[i].next)
		{
			int pos=e2[i].to;
			if(b[pos])continue;b[pos]=1;
			ans[pos]=t+abs(X[pos]-nowx);
		}
		if(nowx==n||nowy==0)
		{
			if (nowx<m-nowy) t+=nowx,nowy+=nowx,nowx=0;
			else t+=m-nowy,nowx-=m-nowy,nowy=m;
		}else
		if(nowx==0||nowy==m)
		{
			if (n-nowx<nowy) t+=n-nowx,nowy-=n-nowx,nowx=n;
			else t+=nowy,nowx+=nowy,nowy=0;
		}
		if(nowx==n&&nowy==m)break;
		if(nowx==n&&nowy==0)break;
		if(nowx==0&&nowy==m)break;
		if(nowx==0&&nowy==0)break;
	}
	for (int i=1; i<=k; i++) printf("%I64d\n",ans[i]);
}