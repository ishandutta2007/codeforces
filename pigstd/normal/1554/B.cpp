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

const int inf=1e18;
const int M=1e5+10;
int n,a[M],k;
struct node
{
	int x,y;
	void clear(){x=y=0;}
	void ins(int a)
	{
		if (a==x||a==y)return;
		y=max(a,y);
		if (y>x)swap(x,y);
	}
	void ins(node a){ins(a.x),ins(a.y);}
}t[M<<1];

signed main()
{
	WT
	{
		n=read(),k=read();int ans=-inf;int kk=log2(n);kk=(1<<(kk+1))-1;
		for (int i=1;i<=n;i++)a[i]=read(),t[a[i]].ins(i);
		for (int i=1;i<=kk;i++)
			for (int j=0;j<=20;j++)
				if (i&(1<<j))t[i].ins(t[i^(1<<j)]);
		for (int i=0;i<=kk;i++)
		{
			if (t[i].y==0)continue;
			ans=max(ans,t[i].x*t[i].y-k*i);
		}
		for (int i=0;i<=kk;i++)t[i].clear();
		cout<<ans<<endl;
	}
	return 0;
}