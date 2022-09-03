// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,m,a[55],b[55],c[55],cnt[55],cv[55][55],pre[55];
LL dp[55][55][5555];
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=n;i++)get1(b[i]);
	
	memcpy(c,a,sizeof(c));sort(c+1,c+n+1);m=unique(c+1,c+n+1)-c-1;reverse(c+1,c+m+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i]==c[j])cv[j][++cnt[j]]=b[i];
	for(int i=1;i<=m;i++)
	{
		sort(cv[i]+1,cv[i]+cnt[i]+1);
		reverse(cv[i]+1,cv[i]+cnt[i]+1);
		for(int j=1;j<=cnt[i];j++)cv[i][j]+=cv[i][j-1];
		pre[i]=pre[i-1]+cnt[i];
	}
	
	for(int i=0;i<55;i++)for(int j=0;j<55;j++)for(int k=0;k<5555;k++)dp[i][j][k]=Linf;
	dp[1][0][0]=0;
	for(int i=1;i<=m;i++)for(int j=0;j<=pre[i-1];j++)for(int k=0;k<5555;k++)if(dp[i][j][k]!=Linf)
	{
		for(int nxt=0;nxt<=cnt[i];nxt++)if(j>=cnt[i]-nxt)
			dp[i+1][j-cnt[i]+nxt+nxt][k+cv[i][nxt]]=min(dp[i+1][j-cnt[i]+nxt+nxt][k+cv[i][nxt]],dp[i][j][k]+1ll*c[i]*nxt);
	}
	
	pair<LL,int> ans=mp(Linf,1);
	for(int j=0;j<=n;j++)for(int k=0;k<5555;k++)if(dp[m+1][j][k]!=Linf)
	{
		if(ans.ff==Linf)ans=mp(dp[m+1][j][k],k);
		else if(ans.ff*k>dp[m+1][j][k]*ans.ss)ans=mp(dp[m+1][j][k],k);
	}
	LL ans1=ans.ff*1000/ans.ss;
	if(ans.ss*ans1<ans.ff*1000)ans1++;
	printendl(ans1);
	return 0;
}