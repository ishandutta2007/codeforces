#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
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
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
char s[100005];
int n,m,a[100005],st[100005],tp,ls[100005],rs[100005],val[100005],rt,ct;
int b[105];
int solve(int l,int r)
{
	//printf("solve:l=%d,r=%d\n",l,r);
	ct++;
	if(l==r)
	{
		val[ct]=s[l];
		return ct;
	}
	int mid=a[l]+1,nw=ct;
	val[nw]=s[mid];
	ls[nw]=solve(l+1,mid-2);
	rs[nw]=solve(mid+2,r-1);
	return nw;
}
int f[205][70005],lim;
int tmp[70005],tmp2[70005];
void fwtor(int *a)
{
	for(int k=1;k<lim;k<<=1)
		for(int i=0,r=k*2;i<lim;i+=r)
			for(int j=0;j<k;j++)
				a[i+j+k]=addmod(a[i+j+k]+a[i+j]);
}
void fwtand(int *a)
{
	for(int k=1;k<lim;k<<=1)
		for(int i=0,r=k*2;i<lim;i+=r)
			for(int j=0;j<k;j++)
				a[i+j]=addmod(a[i+j]+a[i+j+k]);
}
void ifwtor(int *a)
{
	for(int k=1;k<lim;k<<=1)
		for(int i=0,r=k*2;i<lim;i+=r)
			for(int j=0;j<k;j++)
				a[i+j+k]=submod(a[i+j+k]-a[i+j]);
}
void ifwtand(int *a)
{
	for(int k=1;k<lim;k<<=1)
		for(int i=0,r=k*2;i<lim;i+=r)
			for(int j=0;j<k;j++)
				a[i+j]=submod(a[i+j]-a[i+j+k]);
}
void upd(int *a,int *b,int *c)
{
	memcpy(tmp,b,sizeof(tmp));
	memcpy(tmp2,c,sizeof(tmp2));
	fwtor(tmp);
	fwtor(tmp2);
	for(int i=0;i<lim;i++)
		tmp[i]=1ll*tmp[i]*tmp2[i]%mod;
	ifwtor(tmp);
	for(int i=0;i<lim;i++)
		a[i]=addmod(a[i]+tmp[i]);
}
void upd2(int *a,int *b,int *c)
{
	memcpy(tmp,b,sizeof(tmp));
	memcpy(tmp2,c,sizeof(tmp2));
	fwtand(tmp);
	fwtand(tmp2);
	for(int i=0;i<lim;i++)
		tmp[i]=1ll*tmp[i]*tmp2[i]%mod;
	ifwtand(tmp);
	for(int i=0;i<lim;i++)
		a[i]=addmod(a[i]+tmp[i]);
}
void dfs(int u)
{
//	printf("dfs:u=%d,ls=%d,rs=%d,lim=%d\n",u,ls[u],rs[u],lim);
	if(!ls[u]&&!rs[u])
	{
		if(val[u]=='?')
		{
			for(int k=0;k<4;k++)
			{
				int v=k,nw=0;
				for(int i=0;i<16;i++)
					if(i&(1<<v))
						nw|=(1<<i);
				f[u][nw]=1;
				v=k,nw=0;
				for(int i=0;i<16;i++)
					if(!(i&(1<<v)))
						nw|=(1<<i);
				f[u][nw]=1;
			}
		}
		else if(val[u]>='A'&&val[u]<='D')
		{
			int v=val[u]-'A',nw=0;
			for(int i=0;i<16;i++)
				if(i&(1<<v))
					nw|=(1<<i);
			f[u][nw]=1;
		}
		else
		{
			int v=val[u]-'a',nw=0;
			for(int i=0;i<16;i++)
				if(!(i&(1<<v)))
					nw|=(1<<i);
			f[u][nw]=1;
		}
		return;
	}
	dfs(ls[u]);
	dfs(rs[u]);
	if(val[u]!='&') upd(f[u],f[ls[u]],f[rs[u]]);
	if(val[u]!='|') upd2(f[u],f[ls[u]],f[rs[u]]);
}
int main()
{
	memset(b,0xff,sizeof(b));
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
			st[++tp]=i;
		else if(s[i]==')')
		{
			a[st[tp]]=i;
			a[i]=st[tp];
			tp--;
		}
	}
	/*for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	lim=(1<<16);
	rt=solve(1,n);
	dfs(rt);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y=0;
		for(int j=0;j<4;j++)
		{
			scanf("%d",&x);
			y|=(x<<j);
		}
		scanf("%d",&b[y]);
	}
	int ans=0;
	for(int i=0;i<lim;i++)
	{
		int fl=1;
		for(int j=0;j<16;j++)
			if(b[j]!=-1&&((i>>j)&1)!=b[j])
				fl=0;
		if(fl) ans=addmod(ans+f[rt][i]);
	}
	printf("%d\n",ans);
	return 0;
}