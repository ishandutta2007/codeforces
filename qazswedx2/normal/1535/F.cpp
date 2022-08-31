#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int B=2354,mod1=4999997,mod2=1e9+7,mod3=1e9+9;
struct pt
{
	int v1,v2,v3;
	pt(int v1=0,int v2=0,int v3=0):v1(v1),v2(v2),v3(v3){}
};
pt operator+(const pt x,const pt y)
{
	return pt((x.v1+y.v1)%mod1,(x.v2+y.v2)%mod2,(x.v3+y.v3)%mod3);
}
pt operator-(const pt x,const pt y)
{
	return pt((x.v1-y.v1+mod1)%mod1,(x.v2-y.v2+mod2)%mod2,(x.v3-y.v3+mod3)%mod3);
}
pt operator*(const pt x,const pt y)
{
	return pt(1ll*x.v1*y.v1%mod1,1ll*x.v2*y.v2%mod2,1ll*x.v3*y.v3%mod3);
}
struct qwq
{
	struct edge
	{
		pt p;
		int w1,w2,c,nxt;
	}e[500005];
	int h[5000005],t,b[500005],bt;
	void ins(pt p,int w1,int w2)
	{
		int u=p.v1;
	//	printf("ins:p=%d,%d,%d\n",p.v1,p.v2,p.v3); 
		for(int i=h[u];i;i=e[i].nxt)
		{
			pt v=e[i].p;
			if(p.v2==v.v2&&p.v3==v.v3)
			{
				e[i].c++;
				return;
			}
		}
		e[++t].p=p;
		e[t].c=1;
		e[t].w1=w1,e[t].w2=w2;
		e[t].nxt=h[u];
		h[u]=t;
		b[++bt]=u;
	}
	int query(pt p,int w1,int w2)
	{
		for(int i=h[p.v1];i;i=e[i].nxt)
		{
			pt v=e[i].p;
			if(p.v2==v.v2&&p.v3==v.v3)
				return e[i].w1!=w1&&e[i].w2!=w2;
		}
		return 0;
	}
	void getcl()
	{
		for(int i=1;i<=bt;i++)
			h[b[i]]=0;
		t=0;
		bt=0;
	}
}T[4];
struct qt
{
	int v[26],id;
	qt(){memset(v,0,sizeof(v));}
	bool operator<(const qt q) const
	{
		for(int i=0;i<26;i++)
			if(v[i]!=q.v[i])
				return v[i]<q.v[i];
		return 0;
	}
	bool operator==(const qt q) const
	{
		for(int i=0;i<26;i++)
			if(v[i]!=q.v[i])
				return 0;
		return 1;
	}
}a[200005];
int n,m;
pt *f[200005],*g[200005],pw[200005],buff[1000005],bufg[1000005];
char *s[200005],buf[1000005];
int sum[1000005];
ll ans=0;
/*pt F(int x,int l,int r)
{
	return f[(x-1)*m+r]-f[(x-1)*m+l-1]*pw[r-l+1];
}*/
int vis[205],vis2[205];
int check(int x,int y)
{
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=m;i++)
	{
		vis[s[x][i]]++;
		vis2[s[y][i]]++;
	}
	for(int i=0;i<26;i++)
		if(vis[i+'a']!=vis2[i+'a'])
			return 1337;
	int l=0,r=m+1;
	while(l<m&&s[x][l+1]==s[y][l+1]) l++;
	while(r>1&&s[x][r-1]==s[y][r-1]) r--;
	if(l==m) return 0;
	int fl1=1,fl2=1;
	for(int i=l+1;i<r-1;i++)
	{
		if(s[x][i]>s[x][i+1])
			fl1=0;
		if(s[y][i]>s[y][i+1])
			fl2=0;
	}
	if(fl1||fl2) return 1;
	return 2;
}
int main()
{
	scanf("%d",&n);
	s[1]=buf;
	scanf("%s",s[1]+1);
	m=strlen(s[1]+1);
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]+m;
		scanf("%s",s[i]+1);
	}
	pw[0]=pt(1,1,1);
	for(int i=1;i<=m;i++)
		pw[i]=pw[i-1]*pt(B,B,B);
	f[1]=buff,g[1]=bufg;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+m+1;
		g[i]=g[i-1]+m+1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			f[i][j]=f[i][j-1]*pw[1]+pt(s[i][j],s[i][j],s[i][j]);
		for(int j=m;j>0;j--)
			g[i][j]=g[i][j+1]*pw[1]+pt(s[i][j],s[i][j],s[i][j]);
	}
	for(int i=1;i<=n*m;i++)
		sum[i]=sum[i-1]+(buf[i]<buf[i-1]);
	if(n<=800)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				ans+=check(i,j);
			//	printf("i=%d,j=%d,check=%d\n",i,j,check(i,j));
			}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			a[i].v[s[i][j]-'a']++;
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	ll ct=0;
	T[0].getcl();
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&a[r+1]==a[l]) r++;
		ans+=1337ll*(r-l+1)*(l-1);
		ct+=1ll*(r-l+1)*(l-1);
		for(int L=1;L<=m;L++)
			for(int R=L;R<=m;R++)
			{
				for(int u=l;u<=r;u++)
				{
					int i=a[u].id;
					if(sum[(i-1)*m+L]==sum[(i-1)*m+R])
						T[0].ins(f[i][L-1]*pw[m-R]+g[i][R+1],s[i][L],s[i][R]);
				/*	T[1].ins(F(i,1,L)*pw[m-R]+F(i,R+1,m));
					T[2].ins(F(i,1,L-1)*pw[m-R+1]+F(i,R,m));
					T[3].ins(F(i,1,L)*pw[m-R+1]+F(i,R,m));*/ 
				}
				for(int u=l;u<=r;u++)
				{
					int i=a[u].id;
				//	printf("i=%d,L=%d,R=%d,sum=%d,%d\n",i,L,R,sum[(i-1)*m+1+L],sum[(i-1)*m+1+R]);
					int q=0;
					q=T[0].query(f[i][L-1]*pw[m-R]+g[i][R+1],s[i][L],s[i][R]);
					//	printf("q=%d\n",q);
			/*			q-=T[1].query(F(i,1,L)*pw[m-R]+F(i,R+1,m));
					//	printf("q=%d\n",q);
						q-=T[2].query(F(i,1,L-1)*pw[m-R+1]+F(i,R,m));
					//	printf("q=%d\n",q);
						q+=T[3].query(F(i,1,L)*pw[m-R+1]+F(i,R,m));*/
					//	printf("i=%d,L=%d,R=%d,l=%d,r=%d,q=%d\n",i,L,R,l,r,q);
					ct+=q;
					ans+=q;
				}
			//	for(int i=0;i<4;i++)
			//		T[i].getcl();
				T[0].getcl();
			}
	}
	ans+=2*(1ll*n*(n-1)/2-ct);
	printf("%lld\n",ans);
	return 0;
}