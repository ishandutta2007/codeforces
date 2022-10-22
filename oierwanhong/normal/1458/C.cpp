#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 1011;
struct matrix
{
	int a[4][4];
	matrix(){memset(a,0,sizeof a);}
	matrix operator* (const matrix& you)const
	{
		matrix res;
		for(int i=0;i<4;++i)
			for(int k=0;k<4;++k)
				for(int j=0;j<4;++j)res.a[i][j]+=a[i][k]*you.a[k][j];
		return res;
	}
	matrix operator*= (const matrix& you){return (*this)=(*this)*you;}
}res,R,L,D,U,I,C;
int a[MAXN][MAXN],b[MAXN][MAXN];
char s[200011];
int main()
{
	R.a[0][0]=R.a[1][1]=R.a[2][2]=R.a[3][1]=R.a[3][3]=1;
	L.a[0][0]=L.a[1][1]=L.a[2][2]=L.a[3][3]=1,L.a[3][1]=-1;
	D.a[0][0]=D.a[1][1]=D.a[2][2]=D.a[3][0]=D.a[3][3]=1;
	U.a[0][0]=U.a[1][1]=U.a[2][2]=U.a[3][3]=1,U.a[3][0]=-1;
	I.a[0][0]=I.a[1][2]=I.a[2][1]=I.a[3][3]=1;
	C.a[0][2]=C.a[1][1]=C.a[2][0]=C.a[3][3]=1;
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)a[i][j]=read();
		scanf("%s",s+1);
		res=matrix();
		res.a[0][0]=res.a[1][1]=res.a[2][2]=res.a[3][3]=1;
		for(int i=1;i<=m;++i)
			if(s[i]=='R')res*=R;
			else if(s[i]=='L')res*=L;
			else if(s[i]=='D')res*=D;
			else if(s[i]=='U')res*=U;
			else if(s[i]=='I')res*=I;
			else res*=C;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				int k=a[i][j];
				int x=i*res.a[0][0]+j*res.a[1][0]+k*res.a[2][0]+res.a[3][0];
				int y=i*res.a[0][1]+j*res.a[1][1]+k*res.a[2][1]+res.a[3][1];
				int v=i*res.a[0][2]+j*res.a[1][2]+k*res.a[2][2]+res.a[3][2];
				x=((x-1)%n+n)%n+1,y=((y-1)%n+n)%n+1,v=((v-1)%n+n)%n+1;
				b[x][y]=v;
			}
		for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=n;++j)printf("%d ",b[i][j]);
	}
	return 0;
}