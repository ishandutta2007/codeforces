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
int n,a[M],c[M],ans[M],sum[M];
string s;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);cin>>s;int f=1;
	for (int i=1;i<=n;i++)c[i]=s[i-1]=='L'?1:-1;
	if (c[n]==-1){f=-1;for (int i=1;i<=n;i++)c[i]*=-1;}
	int tl=1,tr=n;
	for (int i=(n&1?2:1);i<=n;i+=2)a[i]*=-1;
	for (int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	for (int i=n-1;i>=1;i--)
		if ((sum[tr-1]-sum[tl-1]>0)==(c[i]==1))ans[i+1]=a[tr--];
		else ans[i+1]=a[tl++];
	ans[1]=a[tl];
	for (int i=1;i<=n;i++)ans[i]*=f;
	for (int i=1;i<=n;i++)
		if (ans[i]>0)printf("%lld L\n",ans[i]);
		else printf("%lld R\n",-ans[i]);
	return 0;
}