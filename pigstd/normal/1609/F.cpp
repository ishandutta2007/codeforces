#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e6+10;
int n,a[M],b[M],st1[M],top1,st2[M],top2;

struct BIT
{
	int a[M],b[M];
//	int lowbit(int x){return x&(-x);}
	void add(int x,int k)
	{
		for (int i=x;i<=n;i+=i&(-i))
			a[i]+=k,b[i]+=(x-1)*k;
	}
	void update(int l,int r,int k){add(l,k),add(r+1,-k);}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i^=i&(-i))
			res+=x*a[i]-b[i];
		return res;
	}
	int query(int l,int r){return ask(r)-ask(l-1);}
	void clear(){memset(a,0,sizeof(a));memset(b,0,sizeof(b));}
}T1,T2;

signed main()
{
	n=read();int res=0;
	for (int i=1;i<=n;i++)
		a[i]=read(),b[i]=__builtin_popcountll(a[i]);
	for (int w=0;w<60;w++)
	{
		T1.clear(),T2.clear(),top1=top2=0;
		int now=0;
		for (int i=1;i<=n;i++)
		{
			while(top1>0&&a[i]>a[st1[top1]])
			{
				if (b[st1[top1]]==w)
					T1.update(st1[top1-1]+1,st1[top1],-1),now-=T2.query(st1[top1-1]+1,st1[top1]);
				top1--;
			}
			while(top2>0&&a[i]<a[st2[top2]])
			{
				if (b[st2[top2]]==w)
					T2.update(st2[top2-1]+1,st2[top2],-1),now-=T1.query(st2[top2-1]+1,st2[top2]);
				top2--;
			}
			st1[++top1]=st2[++top2]=i;
			if (b[i]==w)
				T2.update(st2[top2-1]+1,i,1),now+=T2.query(st1[top1-1]+1,i),
				now+=T1.query(st2[top2-1]+1,i),T1.update(st1[top1-1]+1,i,1);
			res+=now;
		}
//		cout<<res<<endl;
	}cout<<res<<endl;
	return 0;
}
// ctr nmsl 
// nmsl nmsl nmsl