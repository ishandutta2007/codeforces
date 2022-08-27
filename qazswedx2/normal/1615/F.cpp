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
struct pt
{
	int p,e;
	pt(int p=0,int e=0):p(p),e(e){}
}f[2005][5005];
inline pt operator+(const pt x,const pt y)
{
	return pt(addmod(x.p+y.p),addmod(x.e+y.e));
}
void upd(pt &x,int y)
{
	x.e=(x.e+1ll*x.p*y)%mod;
}
int T,n,pn=2500;
char a[100005],b[100005];
inline int F(int x)
{
	return x>0?x:-x;
}
void solve(int x,int nw)
{
//	printf("solve:x=%d,nw=%d\n",x,nw); 
	for(int i=pn-n;i<=pn+n;i++)
	//	if(f[x-1][i+pn])
		{
			pt p=f[x-1][i];
			upd(p,F(i-pn));
			f[x][i+nw]=f[x][i+nw]+p;
		//	printf("i=%d,f=%d,%d\n",i,f[x][i+nw].p,f[x][i+nw].e);
		}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s%s",&n,a+1,b+1);
		for(int i=0;i<=n+1;i++)
			for(int j=-n-1;j<=n+1;j++)
				f[i][j+pn]=pt();
		f[0][pn]=pt(1,0);
		for(int i=1;i<=n;i++)
		{
			int fl=1;
			if(i%2) fl=-1;
			if(a[i]!='1'&&b[i]!='1') solve(i,0);
			if(a[i]!='1'&&b[i]!='0') solve(i,fl);
			if(a[i]!='0'&&b[i]!='1') solve(i,-fl);
			if(a[i]!='0'&&b[i]!='0') solve(i,0);
		}
		printf("%d\n",f[n][pn].e);
	}
	return 0;
}