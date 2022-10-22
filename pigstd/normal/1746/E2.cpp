#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vpi vector<pii>
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e9;
const int M=110;
const int N=1e5+10;
int n,dp[M][M],vis[N];
pii p[M][M];
vi S,T;

vi operator + (vi a,vi b)
{
	for (auto x:b)a.pb(x);
	return a;
}

vi operator - (vi a,vi b)
{
	for (auto x:a)vis[x]=1;
	for (auto x:b)vis[x]=0;
	vi res;
	for (auto x:a)
		if (vis[x])vis[x]=0,res.pb(x);
	return res;
}

vi get(vi a,int b){a.resize(b);return a;}

int query(vi a)
{
	cout<<"? "<<a.size();
	for (auto x:a)cout<<' '<<x;
	cout<<endl;string s;cin>>s;
	return s=="YES";
}

signed main()
{
	n=read();
	for (int i=0;i<=100;i++)for (int j=0;j<=100;j++)dp[i][j]=inf;
	for (int s=0;s<=100;s++)
		for (int i=0;i<=s;i++)
		{
			int j=s-i;
			if (s<=2){dp[i][j]=0;continue;}
			dp[i][j]=inf;
			for (int c=0;c<=i;c++)for (int d=0;d<=j;d++)
				if (dp[i][j]>max(dp[c+d][i-c],dp[i-c+j-d][c])+1)
					dp[i][j]=max(dp[c+d][i-c],dp[i-c+j-d][c])+1,p[i][j]=mp(c,d); 
//			cerr<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	int Mid=(n+1)>>1;
	for (int i=1;i<=Mid;i++)S.pb(i);
	for (int i=Mid+1;i<=n;i++)T.pb(i);
	if (!query(S))swap(S,T); 
	while(S.size()+T.size()>100)
	{
		int m1=S.size()>>1,m2=T.size()>>1;
		auto s1=get(S,m1),s2=S-s1,t1=get(T,m2),t2=T-t1;
		if (query(s1+t1))S=s1+t1,T=s2;
		else S=s2+t2,T=s1;
	}
	while(S.size()+T.size()>2)
	{
		auto tmp=p[S.size()][T.size()];
//		cerr<<tmp.x<<' '<<tmp.y<<' '<<dp[S.size()][T.size()]<<'\n';
		auto s1=get(S,tmp.x),s2=S-s1,t1=get(T,tmp.y),t2=T-t1;
		if (query(s1+t1))S=s1+t1,T=s2;
		else S=s2+t2,T=s1;
	}
	S=S+T;
	for (auto x:S)
	{
		cout<<"! "<<x<<endl;
		string s;cin>>s;
		if (s==":)")return 0;
	}
	return 0;
}