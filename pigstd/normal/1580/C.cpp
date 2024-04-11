//GM when? 
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
const int BL=450;
int n,m,x[M],y[M],t[M],C[BL+20][BL+20];

struct BBB// +  O(1)-O(sqrt(n)) 
{
	int sum[BL+20],val[M];
	int L(int x){return (x-1)*BL;}
	int R(int x){return min(m,x*BL-1);}
	int id(int x){return x/BL+1;}
	int ask(int x)
	{
		int res=0;
		for (int i=1;i<id(x);i++)
			res+=sum[i];
		for (int i=L(id(x));i<=x;i++)
			res+=val[i];
		return res;
	}
	void add(int k,int x)
	{
		if (k>m)return;
		sum[id(k)]+=x;
		val[k]+=x;
	}
	void update(int l,int r,int z){add(r+1,-z),add(l,z);}
}T1; 

/*struct fuuuuck
{
	int c[M];
	void update(int l,int r,int z)
	{
//		cout<<l<<' '<<r<<' '<<z<<endl;
		for (int i=l;i<=r;i++)c[i]+=z;
	}
	int ask(int x){return c[x];}
}T1,T2[BL+20];*/

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)x[i]=read(),y[i]=read();
	for (int i=1;i<=m;i++)
	{
		int opt=read(),k=read();
		if (opt==1)t[k]=i;
		int val=opt==1?1:-1;
		int X=x[k],Y=y[k],ti=t[k];
		if (X+Y<=BL)
		{
			int l=(X+ti),r=(X+Y+ti-1);
			for (int i=l;i<=r;i++)
				C[X+Y][i%(X+Y)]+=val;
		}
		else
		{
			for (int j=ti+X;j<=m;j+=X+Y)
				T1.update(j,j+Y-1,val);
		}
		int res=T1.ask(i);
		for (int j=1;j<=BL;j++)
			res+=C[j][i%j];
		printf("%d\n",res);
	}
	return 0;
}