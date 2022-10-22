//AFO countdown:15 Days
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

const int M=1e5+10;
int n,a,b,c,d[M],sum;

int check(int x)
{
	int sum1=0,sum2=0;
	for (int i=1;i<=n;i++)
		if (d[i]<x)sum1+=x-d[i];
		else if (d[i]>x)sum2+=d[i]-x;
	int tmp=min(sum1,sum2),res=tmp*c;
	sum1-=tmp,sum2-=tmp;
	res+=sum1*a+sum2*b;return res;
}

int work(int tl,int tr)
{
	int p=-1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid)-check(Mid-1)<=0)p=Mid,tl=Mid+1;
		else tr=Mid-1;
	}
	return check(p);
}

signed main()
{
	n=read(),a=read(),b=read(),c=min(a+b,read());
//	a=min(a,b+c),b=min(b,a+c);
	for (int i=1;i<=n;i++)d[i]=read(),sum+=d[i];
	sort(d+1,d+1+n);
	int ans=min(work(d[1],sum/n),work(sum/n+1,d[n]));
	cout<<ans<<endl;
	return 0;
}