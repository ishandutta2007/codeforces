#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=3e5+10;
int T,n,a[M],p[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool cmp(int k)
{
	if (k<=1||k>=n)return 0;
	return (a[k]>a[k-1]&&a[k]>a[k+1])||(a[k]<a[k-1]&&a[k]<a[k+1]);
}

int work(int i)
{
	int cnt1=abs(p[i-1])+abs(p[i])+abs(p[i+1]);
	int cnt2=0;
	if (cmp(i))cnt2++;
	if (cmp(i-1))cnt2++;
	if (cmp(i+1))cnt2++;
	return cnt1-cnt2;
}

signed main()
{
	T=read();
	while(T--)
	{
		n=read();int cnt=0;
		for (int i=1;i<=n;i++)
			a[i]=read();
		for (int i=2;i<n;i++)
			if (a[i]>a[i-1]&&a[i]>a[i+1])p[i]=1,cnt++;
			else if (a[i]<a[i-1]&&a[i]<a[i+1])p[i]=-1,cnt++;
		int maxn=0;
		for (int i=1;i<=n;i++)
		{
			int k=a[i];
			a[i]=a[i-1];maxn=max(work(i),maxn);
			a[i]=a[i+1];maxn=max(work(i),maxn);
			a[i]=max(a[i-1],a[i+1])-1;maxn=max(work(i),maxn);
			a[i]=min(a[i-1],a[i+1])-1;maxn=max(work(i),maxn);
			a[i]=max(a[i-1],a[i+1])+1;maxn=max(work(i),maxn);
			a[i]=0;maxn=max(work(i),maxn);
			a[i]=1e9+10;maxn=max(work(i),maxn);
			a[i]=k;
		}
		cout<<max(0ll,cnt-maxn)<<endl;
		for (int i=1;i<=n;i++)p[i]=0;
	}
	return 0;
}