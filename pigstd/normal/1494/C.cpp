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

const int M=2e5+10;
int n,m,p1,p2,ans,a[M],b[M];
map<int,int>t;

int work1()
{
	int cnt=0,maxn=0;
	for (int i=1;i<=p2;i++)
	{
		int res=0;
		int tl=1,tr=n,p=n+1;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (a[Mid]>=b[i])p=Mid,tr=Mid-1;
			else tl=Mid+1;
		}if (p>p1)break;
		int x=p1-p+1;
		tl=1,tr=m;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (b[Mid]<=b[i]+x-1)tl=Mid+1,p=Mid;
			else tr=Mid-1;
		}res=p-i+1;
		maxn=max(maxn,res+cnt);cnt+=t[b[i]];
	}maxn=max(maxn,cnt);return maxn;
}

int work2()
{
	int cnt=0,maxn=0;
	for (int i=m;i>p2;i--)
	{
		int res=0;
		int tl=1,tr=n,p=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (a[Mid]<=b[i])p=Mid,tl=Mid+1;
			else tr=Mid-1;
		}if (p<=p1)break;
		int x=p-p1;
		tl=1,tr=m;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (b[Mid]>=b[i]-x+1)tr=Mid-1,p=Mid;
			else tl=Mid+1;
		}res=i-p+1;
		maxn=max(maxn,res+cnt);cnt+=t[b[i]];
	}maxn=max(maxn,cnt);return maxn;
	return 0;
}

signed main()
{
	WT
	{
		n=read(),m=read();t.clear();p1=p2=ans=0;
		for (int i=1;i<=n;i++)a[i]=read(),t[a[i]]=1,p1=a[i]<0?i:p1;
		for (int i=1;i<=m;i++)b[i]=read(),p2=b[i]<0?i:p2;
		ans+=work1();ans+=work2();
		cout<<ans<<endl;
	}
	return 0;
}