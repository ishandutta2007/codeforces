#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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
const int N=22;
int n,k,a[M],l,r,ans,cnt[M];
int dp[M][N];

void add(int x){ans-=cnt[x]*(cnt[x]-1)/2;cnt[x]++;ans+=cnt[x]*(cnt[x]-1)/2;}
void del(int x){ans-=cnt[x]*(cnt[x]-1)/2;cnt[x]--;ans+=cnt[x]*(cnt[x]-1)/2;}

int find(int ll,int rr)
{
	while(r<rr)add(a[++r]);
	while(l>ll)add(a[--l]);
	while(r>rr)del(a[r--]);
	while(l<ll)del(a[l++]);
	return ans;
}

void work(int l,int r,int ll,int rr,int p)
{
	if (l>r)return;
	int pp=0,Mid=(l+r)>>1;dp[Mid][p]=inf;
	for (int i=ll;i<=rr&&i<Mid;i++)
		if (dp[i][p-1]+find(i+1,Mid)<dp[Mid][p])
			pp=i,dp[Mid][p]=dp[i][p-1]+find(i+1,Mid);
	work(l,Mid-1,ll,pp,p);work(Mid+1,r,pp,rr,p);
}

signed main()
{
	l=1,r=0;
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=1;i<=n;i++)
		dp[i][1]=find(1,i);
	for (int i=2;i<=k;i++)
		work(1,n,0,n-1,i);
	cout<<dp[n][k]<<endl;
	return 0;
}