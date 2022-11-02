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
#define OUT fflush(stdout)
#define sz 10100

int n;
int t1[sz]; // p_i^b_i
int t2[sz]; // b_i^p_{i+1}
int ask(int i,int j){printf("? %d %d\n",i,j);OUT;int ret;read(ret);return ret;}
int p[sz],b[sz];

int main()
{
//	file();
	read(n);
	rep(i,0,n-1) t1[i]=ask(i,i);
	rep(i,0,n-1) t2[i]=ask((i+1)%n,i);
	int cnt=0;
	vector<int>ans;
	rep(k,0,n-1)
	{
		p[0]=k;
		rep(i,0,n-1) b[i]=p[i]^t1[i],p[(i+1)%n]=b[i]^t2[i];
		int flg=1;
		rep(i,0,n-1) if (p[b[i]]!=i) flg=0;
		if (!flg) continue;
		++cnt;
		if (cnt==1) rep(i,0,n-1) ans.push_back(p[i]);
	}
	puts("!");
	printf("%d\n",cnt);
	rep(i,0,n-1) printf("%d ",ans[i]);
	OUT;
	return 0;
}