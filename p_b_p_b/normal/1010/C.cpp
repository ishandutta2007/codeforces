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
#define sz 101001
int gcd(int x,int y){return y?gcd(y,x%y):x;}

int n,K;
int vis[sz];

int main()
{
	file();
	read(n),read(K);
	int x,cur=-1;
	rep(i,1,n)
	{
		read(x);x%=K;
		if (!x) continue;
		if (cur==-1) cur=x; else cur=gcd(cur,x);
	}
	if (cur==-1) return puts("1\n0"),0;
	cur=gcd(cur,K);
	printf("%d\n",(K-1)/cur+1);
	rep(i,0,K-1) if (i%cur==0) printf("%d ",i);
	return 0;
}