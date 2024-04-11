#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=4e5+10;
int n,a[M],b[M],ans;

int work(int l,int r)
{
	if (l>r)return 0;
	int cnt=0;
	for (int i=n,tl=1,tr=1;i>=1;i--)
	{
		while(tl<=n&&b[i]+b[tl]<l)tl++;
		while(tr<=n&&b[i]+b[tr]<=r)tr++;
		cnt+=tr-tl;
		if (i<tr&&i>=tl)cnt--;
	}
	return cnt>>1;
}

int solve(int k)
{
	for (int i=1;i<=n;i++)b[i]=a[i]&((2<<k)-1);
	sort(b+1,b+1+n);
	return (work(1<<k,(2<<k)-1)+work(3<<k,(4<<k)-2))&1;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=0;i<=30;i++)
		ans+=(1<<i)*solve(i);
	cout<<ans;
	return 0;
}