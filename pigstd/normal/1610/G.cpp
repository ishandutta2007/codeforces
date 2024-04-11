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

const int Mod=998244353;
const int M=3e5+10;
int a[M],ans[M],top,n,t[M<<1],p[M],hs[M],pow3[M],sum[M];
string s;

int min(int a,int b){return a<b?a:b;}

struct ST
{
	int lg2[M],f[25][M];
	void init()
	{
		for (int i=1;i<=n;i++)f[0][i]=sum[i];
		for (int i=2;i<=n;i++)lg2[i]=lg2[i>>1]+1;
		for (int i=1;i<=20;i++)
			for (int j=1;j+(1<<i)-1<=n;j++)
				f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	int query(int l,int r)
	{
		int k=lg2[r-l+1];
		return min(f[k][l],f[k][r-(1<<k)+1]);
	}
}T;

int get_hash(int l,int r)
{
	int len=r-l+1;
	return (hs[r]-hs[l-1]*pow3[len]%Mod+Mod)%Mod;
}

signed main()
{
	cin>>s;n=s.size();pow3[0]=1;
	for (int i=1;i<=n;i++)a[i]=s[i-1]=='('?1:2,pow3[i]=pow3[i-1]*3%Mod;
	for (int i=1;i<=n;i++)sum[i]=sum[i-1]+(a[i]==1?1:-1);
	T.init();
	for (int i=n;i>=1;i--)
	{
		ans[++top]=i,p[i]=top;t[sum[i]+M]=i;
		hs[top]=(hs[top-1]*3+a[i])%Mod;
		int pos=t[sum[i-1]+M];if (!pos)continue;
		if (T.query(i,pos)<sum[i-1])continue;
		int p2=p[pos];assert(ans[p2]==pos);
		int tl=1,tr=p2-1,p=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (get_hash(p2-Mid,p2-1)==get_hash(top-Mid+1,top))p=Mid,tl=Mid+1;
			else tr=Mid-1;
		}
		if (a[ans[p2-1-p]]<a[ans[top-p]])
			// delete pos - top
			top=p2-1;
	}
	if (top==0)puts("()");
	for (int i=top;i>=1;i--)
		if (a[ans[i]]==1)printf("(");
		else printf(")");
	return 0;
}
/*
()(()))
*/