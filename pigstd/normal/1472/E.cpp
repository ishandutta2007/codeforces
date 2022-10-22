#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=4e5+10;
int T,n,ans[M];

struct node
{
	int w,h,id;
}a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool cmp(node a,node b)
{
	return a.w<b.w;
}

signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		for (int i=1;i<=n;i++)
		{
			a[2*i-1].w=read(),a[2*i-1].h=read(),a[2*i-1].id=i;
			a[2*i]=a[2*i-1];swap(a[2*i].w,a[2*i].h);
		}
		sort(a+1,a+1+2*n,cmp);
		int minn=1e18,p=-1,nminn=1e18,np=-1;
		for (int i=1;i<=n*2;i++)
		{
			if (a[i].w!=a[i-1].w)
			{
				if (minn>nminn)minn=nminn,p=np;
				np=-1,nminn=1e18;
			}
			if (a[i].h>minn)ans[a[i].id]=p;
			if (a[i].h<nminn)nminn=a[i].h,np=a[i].id;
		}
		for (int i=1;i<=n;i++)
			cout<<(ans[i]==0?-1:ans[i])<<' ';
		puts("");
		for (int i=1;i<=n;i++)ans[i]=0;
		for (int i=1;i<=2*n;i++)a[i].w=a[i].h=a[i].id=0;
	}
}
/*
1
2
2 5
6 2
*/