#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
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
int n,m,fr[500005],infr[500005],pn=5e5,inv2;
int a,b;
char s[500005];
inline int C(int x,int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
struct pt
{
	int x,y,v;
	pt(int x=0,int y=0,int v=1):x(x),y(y),v(v){}
	void insy()
	{
		y++;
		v=addmod(v+C(x,y));
	}
	void dely()
	{
		v=submod(v-C(x,y));
		y--;
	}
	void insx()
	{
		x++;
		v=submod(2*v%mod-C(x-1,y));
	}
	void delx()
	{
		v=1ll*inv2*addmod(v+C(x-1,y))%mod;
		x--;
	}
}p[4];
int G(int x,int y,int fl)
{
	if(x==-1) return y>=0&&y%2==0;
	while(p[fl].x>x) p[fl].delx();
	while(p[fl].x<x) p[fl].insx();
	while(p[fl].y>y) p[fl].dely();
	while(p[fl].y<y) p[fl].insy();
	return p[fl].v;
}
/*int G(int x,int y,int fl)
{
	if(x==-1&&y>=0) return 1;
	int ans=0;
	for(int i=0;i<=y;i++)
		ans=addmod(ans+C(x,i));
	return ans;
}*/
int solve()
{
//	printf("solve:a=%d,b=%d\n",a,b);
	return (1ll*b*G(a-1,b-2,0)%mod-1ll*a*G(a-2,b-3,1)%mod+
			1ll*a*G(a-2,a-b-2,2)%mod-1ll*b*G(a-1,a-b-2,3)%mod+4ll*mod)%mod;
}
int solve2()
{
	return 1ll*fpow(inv2,a)*solve()%mod;
}
int main()
{
	inv2=fpow(2,mod-2);
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*i*fr[i-1]%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?') a++;
		else if((s[i]=='w')^(i%2)) b++;
	}
	b=n/2-b;
	printf("%d\n",solve2());
	for(int i=1;i<=m;i++)
	{
		char ch;
		int x;
		scanf("%d %c",&x,&ch);
		if(s[x]=='?') a--;
		else if((s[x]=='w')^(x%2)) b++;
		s[x]=ch;
		if(s[x]=='?') a++;
		else if((s[x]=='w')^(x%2)) b--;
		printf("%d\n",solve2());
	}
	return 0;
}