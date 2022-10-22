#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}


const int M=4e5+10;
int n,a[M],t[M],b[M],l,r;

signed main()
{
	WT
	{
		n=read();r=0;
		for (int i=1;i<=2*n;i++)t[i]=0;
		for (int i=1;i<=n;i++)t[a[i]=read()]=1;
		for (int i=1;i<=2*n;i++)
			if (t[i]==0)b[++r]=i;l=1;
		int minn=0,maxn=0;
		for (int i=1;i<=n;i++)
		{
			while(l<=n&&b[l]<a[i])l++;
			if (b[l]>a[i]&&l!=n+1)l++,minn++;
		}
		for (int i=n;i>=1;i--)
		{
			while(r>=1&&b[r]>a[i])r--;
			if (b[r]<a[i]&&r!=0)r--,maxn++;
		}maxn=n-maxn;
		cout<<minn-maxn+1<<endl;
	}
	return 0;
}
/*
1
2
3 4*/