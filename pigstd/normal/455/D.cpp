//AFO countdown:11 Days
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

const int M=1e5+10;
const int N=410;
int n,la,bl,a[M],cnt[N][M],tmp[N];
int id(int x){return (x-1)/bl+1;}
int L(int x){return (x-1)*bl+1;}
int R(int x){return min(n,x*bl);}
struct Queue
{
	int a[N],len,st;
	void ins(int x)
	{
		st=(st-1+len)%len;
		a[st]=x;
	}
	int Getend(){return a[(st-1+len)%len];}
	int find(int x){return a[(x+st)%n];}
	void ST_0()
	{
		for (int i=st;i<len;i++)tmp[i-st]=a[i];
		for (int i=0;i<st;i++)tmp[len-st+i]=a[i];
		for (int i=0;i<len;i++)a[i]=tmp[i];st=0;
	}
}Q[N];

signed main()
{
	n=read();bl=sqrt(n);//cout<<bl<<endl;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=id(n);i++)
		for (int j=L(i);j<=R(i);j++)
			Q[i].a[Q[i].len++]=a[j],cnt[i][a[j]]++;
	WT
	{
		int opt=read(),l=(read()+la-1)%n+1,r=(read()+la-1)%n+1;
		if (l>r)swap(l,r);
		if (opt==1)
		{
			if (id(l)==id(r))
			{
				int k=id(l);Q[k].ST_0();
				r-=L(k),l-=L(k);int tmp=Q[k].a[r];
				for (int i=r;i>l;i--)
					Q[k].a[i]=Q[k].a[i-1];
				Q[k].a[l]=tmp;continue;
			}int k1=id(l),k2=id(r);
			Q[k1].ST_0(),Q[k2].ST_0();
			int tmp=Q[k2].a[r-L(k2)];
			cnt[k2][tmp]--;cnt[k1][tmp]++;
			for (int i=r-L(k2);i>0;i--)
				Q[k2].a[i]=Q[k2].a[i-1];
			Q[k2].a[0]=Q[k2-1].Getend(),
			cnt[k2][Q[k2].a[0]]++,cnt[k2-1][Q[k2].a[0]]--;
			for (int i=k2-1;i>k1;i--)
			{
				int x=Q[i-1].Getend();
				Q[i].ins(x);cnt[i][x]++,cnt[i-1][x]--;
			}
			for (int i=Q[k1].len-1;i>l-L(k1);i--)
				Q[k1].a[i]=Q[k1].a[i-1];
			Q[k1].a[l-L(k1)]=tmp;
		}
		else
		{
			int x=(read()+la-1)%n+1;
			if (id(l)==id(r))
			{
				int res=0;Q[id(l)].ST_0();
				for (int i=l-L(id(l));i<=r-L(id(l));i++)
					if (Q[id(l)].a[i]==x)res++;
				printf("%d\n",la=res);continue;
			}int res=0,k1=id(l),k2=id(r);
			for (int i=id(l)+1;i<=id(r)-1;i++)
				res+=cnt[i][x];
			Q[k1].ST_0(),Q[k2].ST_0();
			for (int i=l-L(k1);i<Q[k1].len;i++)
				if (Q[k1].find(i)==x)res++;
			for (int i=0;i<=r-L(k2);i++)
				if (Q[k2].find(i)==x)res++;
			printf("%d\n",la=res);
		}
	}
	return 0;
}