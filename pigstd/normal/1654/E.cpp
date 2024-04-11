#include<bits/stdc++.h>
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

const int M=1e5+10;
int t[M<<1],n,a[M],b[M],res=1;

signed main()
{
//	freopen("qwq.txt","r",stdin);
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=-200;i<=200;i++)
	{
		for (int j=1;j<=n;j++)b[j]=a[j]-i*j;
		sort(b+1,b+1+n);int cnt=1;
		for (int j=2;j<=n;j++)
			if (b[j]==b[j-1])cnt++,ckmax(res,cnt);
			else cnt=1;
	}//puts("qwq"); 
	for (int i=1;i<=n;i++)
	{
		for (int j=max(1,i-1000);j<=min(i+1000,n);j++)
			if ((i!=j)&&(a[i]-a[j])%(i-j)==0)t[(a[i]-a[j])/(i-j)+100000]++;
		for (int j=max(1,i-1000);j<=min(i+1000,n);j++)
			if ((i!=j)&&(a[i]-a[j])%(i-j)==0)
				ckmax(res,t[(a[i]-a[j])/(i-j)+100000]+1),t[(a[i]-a[j])/(i-j)+100000]=0;
	}
	cout<<n-res<<'\n';
	return 0;
}