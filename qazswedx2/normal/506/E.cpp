#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=10007;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return ans;
}
struct mat
{
	int x,y,v[805][805];
	mat(){x=y=0,memset(v,0,sizeof(v));}
}ms,mg;
mat operator*(mat a,mat b)
{
	mat c;
	c.x=a.x;
	c.y=b.y;
	for(int i=1;i<=c.x;i++)
		for(int j=1;j<=c.y;j++)
			for(int k=1;k<=a.y;k++)
				c.v[i][j]=addmod(c.v[i][j]+a.v[i][k]*b.v[k][j]%mod);
	return c;
}
struct poly
{
	int a[805],len;
	poly(){len=0;memset(a,0,sizeof(a));}
};
poly operator+(poly x,poly y)
{
	poly z;
	z.len=max(x.len,y.len);
	for(int i=0;i<z.len;i++)
		z.a[i]=addmod(x.a[i]+y.a[i]);
	return z;
}
poly operator*(poly x,poly y)
{
	poly z;
	z.len=x.len+y.len-1;
	for(int i=0;i<x.len;i++)
		for(int j=0;j<y.len;j++)
			z.a[i+j]=addmod(z.a[i+j]+x.a[i]*y.a[j]%mod);
	return z;
}
poly operator/(poly x,poly y)
{
	poly z;
	z.len=y.len;
	for(int i=0;i<z.len;i++)
	{
		z.a[i]=x.a[i];
		for(int j=0;j<i;j++)
			z.a[i]=submod(z.a[i]-z.a[j]*y.a[i-j]%mod);
	}
	return z;
}
poly pfpow(poly x,int y)
{
	poly ans;
	ans.len=1;
	ans.a[0]=1;
	while(y)
	{
		if(y&1) ans=ans*x;
		x=x*x;
		y/=2;
	}
	return ans;
}
mat mfpow(mat x,int y)
{
	mat ans;
	ans=x;
	y--;
	while(y)
	{
		if(y&1) ans=ans*x;
		x=x*x;
		y/=2;
	}
	return ans;
}
int n,m,g[205][205][2];
char s[100005];
poly f[205][205],p[205],q[205],st,ans,p2;
void print(poly x)
{
	for(int i=0;i<x.len;i++)
		printf("%d ",x.a[i]);
}
int main()
{
	scanf("%s%d",s+1,&m);
	p[1].len=q[1].len=st.len=2;
	p2.len=2;
	p2.a[0]=1,p2.a[1]=mod-26;
	st.a[1]=1;
	p[1].a[0]=1,p[1].a[1]=mod-24;
	q[1].a[0]=1,q[1].a[1]=mod-25;
	p[0].len=1;
	p[0].a[0]=1;
	q[0]=p[0];
	n=strlen(s+1);
	for(int i=2;i<=n;i++)
	{
		p[i]=p[1]*p[i-1];
		q[i]=q[1]*q[i-1];
	/*	printf("p=");
		print(p[i]);
		printf("\n");
		printf("q=");
		print(q[i]);
		printf("\n");*/
	}
	for(int i=1;i<=n;i++)
	{
		g[i][i][1]=1;
		if((n+m)%2)
		{
			f[i][i].len=1;
			f[i][i].a[0]=1;
		}
		else
		{
			f[i][i].len=2;
			f[i][i].a[1]=1;
		}
	}
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			if(s[l]!=s[r])
			{
				g[l][r][0]=max(g[l][r-1][0],g[l+1][r][0]);
				g[l][r][1]=max(g[l][r-1][1],g[l+1][r][1]);
				f[l][r]=f[l+1][r]*p[g[l][r][0]-g[l+1][r][0]]*q[g[l][r][1]-g[l+1][r][1]]+
						f[l][r-1]*p[g[l][r][0]-g[l][r-1][0]]*q[g[l][r][1]-g[l][r-1][1]];
				f[l][r]=f[l][r]*st;
				g[l][r][0]++;
			}
			if(s[l]==s[r])
			{
				g[l][r][0]=g[l+1][r-1][0];
				g[l][r][1]=g[l+1][r-1][1];
				f[l][r]=f[l+1][r-1]*st;
				if(len==2)
				{
					f[l][r]=st;
					if((m+n)%2) f[l][r].a[1]=26;
				}
				g[l][r][1]++;
			}
		/*	printf("l=%d,r=%d,g=%d,%d\n",l,r,g[l][r][0],g[l][r][1]);
			printf("f=");
			print(f[l][r]);
			printf("\n");*/
		}
	ans=p[g[1][n][0]]*q[g[1][n][1]];
	ans=ans*p2;
	poly nw=f[1][n]/ans;
	/*printf("nw=");
	print(nw);
	printf("\n");
	printf("ans=");
	print(ans);
	printf("\n");*/
	mg.x=mg.y=ms.x=nw.len-1;
	ms.y=1;
	for(int i=1;i<=ms.x;i++)
		ms.v[i][1]=nw.a[i-1];
	for(int i=1;i<mg.x;i++)
		mg.v[i][i+1]=1;
	int inv=fpow(ans.a[0],mod-2);
	for(int i=0;i<ans.len;i++)
		ans.a[i]=1ll*ans.a[i]*inv%mod;
	for(int i=1;i<=mg.x;i++)
		mg.v[mg.x][i]=(mod-ans.a[mg.x-i+1])%mod;
	m=(m+n)/2;
	if(m<nw.len)
	{
		printf("%d\n",nw.a[m]);
		return 0;
	}
	ms=mfpow(mg,m-nw.len+2)*ms;
	printf("%d\n",ms.v[ms.x][1]);
	return 0;
}