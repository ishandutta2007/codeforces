#include<bits/stdc++.h>
using namespace std;
clock_t __t=clock();
#define rep(i,x,y) for (int i=(x);i<=(y);++i)
#define drep(i,y,x) for (int i=(y);i>=(x);--i)
#define temp template<typename T>
temp bool chkmin(T &x,T y){return x>y?x=y,1:0;}
temp bool chkmax(T &x,T y){return x<y?x=y,1:0;}
#define ll long long
#define db double
void file()
{
	#ifdef NTFAKIOI
	freopen("a.in","r",stdin);
	#endif
}
void chktime()
{
	#ifdef NTFAKIOI
	cout<<1.0*(clock()-__t)/1000;
	#endif
}
temp void read(T &x)
{
	x=0;char ch=getchar(),t=0;
	while (ch>'9'||ch<'0') t|=(ch=='-'),ch=getchar();
	while (ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	x=(t?-x:x);
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define pii pair<int,int>
#define fir first
#define sec second
#define MP make_pair

int main()
{
	file();
	int Q;read(Q);
	while (Q--)
	{
		int n;read(n);
		if (n==6||n==4||n==9) { puts("1"); continue; }
		if ((n<=9&&n!=8)||n==11) { puts("-1"); continue; }
		int s=n/4,z=n%4;
		if (!z) printf("%d\n",s);
		else if (z==1) printf("%d\n",s-1);
		else if (z==2) printf("%d\n",s);
		else printf("%d\n",s-1);
	}
	return 0;
}