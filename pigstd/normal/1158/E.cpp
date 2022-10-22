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

const int M=1010; 
vector<pair<vector<int>,vector<int>>>v;
vector<int>V[3];
int n,dep[M],a[M],vis[M],b[M],fa[M],B;
string s;

void work(vector<int>x,vector<int>y)
{
	memset(vis,0,sizeof(vis));
	for (auto x:y)vis[x]=1;
	for (int i=B;i>=0;i--)
	{
		cout<<"?";
		for (int j=1;j<=n;j++)
			if (vis[j]&&((j-1)>>i)&1)cout<<" 1";
			else cout<<" 0";
		cout<<endl;
		cin>>s;
		for (auto t:x)
			if (s[t-1]=='1')fa[t]|=1<<i;
	}
}

signed main()
{
	n=read();int tmp=n-1;
	while(tmp!=1)tmp/=2,B++;
	v.resize(1);v[0].x.pb(1);
	for (int i=2;i<=n;i++)v[0].y.pb(i);
	for (int i=B;i>=1;i--)
	{
		memset(a,0,sizeof(a));
		memset(vis,-1,sizeof(vis));
		vector<pair<vector<int>,vector<int>>>vv;
		vv.resize(v.size()*2);
		for (int j=0;j<(int)(v.size());j+=2)
		{
			for (auto x:v[j].x)a[x]=1<<i;
			for (auto x:v[j].y)vis[x]=j;
			vv[j*2].x=v[j].x;
		}
		cout<<"?";
		for (int j=1;j<=n;j++)cout<<' '<<a[j];
		cout<<endl;
		cin>>s;
		for (int j=1;j<=n;j++)
			if (vis[j]!=-1)
			{
				if (s[j-1]=='0')vis[j]=vis[j]*2+1;
				else vis[j]=vis[j]*2;
			}
		for (int j=1;j<=n;j++)if (a[j])a[j]--;
		cout<<"?";
		for (int j=1;j<=n;j++)cout<<' '<<a[j];
		cout<<endl;
		cin>>s;
		for (int j=1;j<=n;j++)
			if (vis[j]!=-1)
			{
				if (s[j-1]=='1')vv[vis[j]].y.pb(j);
				else if (vis[j]&1)vv[vis[j]].y.pb(j);
				else vv[vis[j]+1].x.pb(j);
			}
		if (v.size()!=1)
		{
			memset(a,0,sizeof(a));
			memset(vis,-1,sizeof(vis));
			for (int j=1;j<(int)(v.size());j+=2)
			{
				for (auto x:v[j].x)a[x]=1<<i;
				for (auto x:v[j].y)vis[x]=j;
				vv[j*2].x=v[j].x;
			}
			cout<<"?";
			for (int j=1;j<=n;j++)cout<<' '<<a[j];
			cout<<endl;
			cin>>s;
			for (int j=1;j<=n;j++)
				if (vis[j]!=-1)
				{
					if (s[j-1]=='0')vis[j]=vis[j]*2+1;
					else vis[j]=vis[j]*2;
				}
			for (int j=1;j<=n;j++)if (a[j])a[j]--;
			cout<<"?";
			for (int j=1;j<=n;j++)cout<<' '<<a[j];
			cout<<endl;
			cin>>s;
			for (int j=1;j<=n;j++)
				if (vis[j]!=-1)
				{
					if (s[j-1]=='1')vv[vis[j]].y.pb(j);
					else if (vis[j]&1)vv[vis[j]].y.pb(j);
					else vv[vis[j]+1].x.pb(j);
				}
		}
		v.clear();
		for (auto x:vv)
			if (x.x.size())v.pb(x);
	}
	tmp=0;
	for (int i=0;i<(int)(v.size());i++)
	{
		for (auto x:v[i].x)dep[x]=tmp;
		tmp++;
		for (auto x:v[i].y)dep[x]=tmp;
		tmp++;
	}
	for (int i=2;i<=n;i++)V[dep[i]%3].pb(i);
	for (int i=0;i<3;i++)
		work(V[(i+1)%3],V[i]);
	cout<<"!"<<endl;
	for (int i=2;i<=n;i++)cout<<i<<' '<<fa[i]+1<<endl;
	return 0;
}