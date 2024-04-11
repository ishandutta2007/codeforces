//AFO countdown:3 Days
#include<bits/stdc++.h>
#define int long long
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

const int Mod=1e9+7;
const int M=50010;
const int N=40;
int n,k,a[M];

struct tree
{
	int son[2],val1,val2;
}t[M*N];int cnt;

void clear()
{
	for (int i=0;i<=cnt;i++)
		t[i].son[0]=t[i].son[1]=t[i].val1=t[i].val2=0;
	cnt=0;
}

void insert(int x,int y)
{
	int now=0;
	for (int i=31;i>=0;i--)
	{
		int c=((1<<i)&x)?1:0;
		if (!t[now].son[c])
			t[now].son[c]=++cnt;
		now=t[now].son[c];
		t[now].val1++,t[now].val2+=y;
	}
}

int check(int k)
{
	clear();int res=0;
	for (int i=1;i<=n;i++)
	{
		int now=0;
		for (int j=31;j>=0;j--)
		{
			int c1=((1<<j)&a[i])?1:0,c2=((1<<j)&k)?1:0;
			if (c2==0)
				res+=t[t[now].son[c1^1]].val1;
			now=t[now].son[c2^c1];
			if (now==0)break;
		}
		res+=t[now].val1;
		insert(a[i],0);
	}
	return res;
}

int work(int k,int p)
{
	clear();int res=0;
	for (int i=1;i<=n;i++)
	{
		int now=0,pp=(1<<p)&a[i];
		for (int j=31;j>=0;j--)
		{
			int c1=((1<<j)&a[i])?1:0,c2=((1<<j)&k)?1:0;
			if (c2==0)
				res+=pp?t[t[now].son[c1^1]].val1-t[t[now].son[c1^1]].val2:t[t[now].son[c1^1]].val2;
			now=t[now].son[c2^c1];
			if (now==0)break;
		}
		res+=pp?t[now].val1-t[now].val2:t[now].val2;
		insert(a[i],(a[i]&(1<<p))?1:0);
	}
	return res;
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	int tl=0,tr=2e9,p;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid)<=k)p=Mid,tr=Mid-1;
//		cout<<Mid<<' '<<check(Mid)<<endl;
		else tl=Mid+1;
	}//p=3;
//	cout<<p<<' '<<check(p)<<endl;
//	cout<<check(4)<<endl;
//	cout<<check(1)<<' '<<check(2)<<' '<<check(3)<<endl;
	int ans=(k-check(p))%Mod*(p-1)%Mod;
	for (int i=0;i<=31;i++)
		ans+=(1<<i)*work(p,i),ans%=Mod;
	cout<<ans<<endl;
	return 0;
}