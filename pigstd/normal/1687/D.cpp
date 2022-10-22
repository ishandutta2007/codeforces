#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e6+10;
int n,a[M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=2;i<=n;i++)a[i]-=a[1];
	a[n+1]=-1;
	for (int i=1;;i++)
	{
		if (i*(i+1)<a[1])continue;
		int l=max(0ll,a[1]-i*i),r=i;
		for (int j=i;;j++)
		{
			if (a[n]+a[1]+i*i+i<j*j)break;
			int x=*lower_bound(a+2,a+n+1,j*j-i*i-i);
			if (x!=-1&&x+i*i<j*j)ckmax(l,j*j-x-i*i);
			x=upper_bound(a+2,a+n+1,j*j+2*j-i*i-i)-a-1;
			if (x!=1&&a[x]+i*i+i>j*j+j)
				ckmin(r,j*j+j-a[x]-i*i);
			if (l>r)break;
		}
		if (l<=r)return cout<<l+i*i-a[1]<<'\n',0;
	}
	return 0;
}