#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int M=3e5+10;
int n,m,a[M],b[M],ans[M],st[M];
int X,Y,vis[M];
vector<pair<int,int> >v[2];

void solve()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read(),ans[i]=-1;
	for (int i=1;i<=n;i++)
	{
		string s;cin>>s;
		b[i]=s=="L"?1:-1;
	}v[0].clear(),v[1].clear();
	for (int i=1;i<=n;i++)
		if (a[i]&1)v[0].pb(mp(a[i],i));
		else v[1].pb(mp(a[i],i));
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	if (v[0].size()!=0)
	{
		for (int i=1;i<=n;i++)vis[i]=0;int top=0;
		for (int i=v[0].size()-1;i>=0;i--)
		{
			if (b[v[0][i].y]==1)st[++top]=v[0][i].y;
			else if (top)
				ans[v[0][i].y]=ans[st[top]]=abs(a[st[top]]-a[v[0][i].y])/2,
				vis[v[0][i].y]=vis[st[top]]=1,top--;
		}top=0;
		for (int i=v[0].size()-1;i>=0;i--)
			if (!vis[v[0][i].y])st[++top]=v[0][i].y;
		for (int i=1;i<=top;i++)vis[i]=1;
		for (int i=1;i+1<=top;i+=2)
		{
			if (b[st[i]]!=-1||b[st[i+1]]!=-1)break;
			ans[st[i]]=ans[st[i+1]]=abs(a[st[i]]-a[st[i+1]])/2+m-max(a[st[i]],a[st[i+1]]);
			vis[i]=vis[i+1]=0;
		}
		for (int i=top;i-1>=1;i-=2)
		{
			if (b[st[i]]!=1||b[st[i-1]]!=1)break;
			ans[st[i]]=ans[st[i-1]]=abs(a[st[i]]-a[st[i-1]])/2+min(a[st[i]],a[st[i-1]]);
			vis[i]=vis[i-1]=0;
		}X=Y=0;
		for (int i=1;i<=top;i++)
			if (vis[i])
			{
				if (!X)X=i;
				else Y=i;
			}
		if (Y)ans[st[X]]=ans[st[Y]]=abs(2*m-a[st[X]]+a[st[Y]])/2;
	}
	if (v[1].size()!=0)
	{
		for (int i=1;i<=n;i++)vis[i]=0;int top=0;
		for (int i=v[1].size()-1;i>=0;i--)
		{
//			cout<<i<<' '<<v[1][i].y<<endl;
			if (b[v[1][i].y]==1)st[++top]=v[1][i].y;
			else if (top)
				ans[v[1][i].y]=ans[st[top]]=abs(a[st[top]]-a[v[1][i].y])/2,
				vis[v[1][i].y]=vis[st[top]]=1,top--;
		}top=0;
		for (int i=v[1].size()-1;i>=0;i--)
			if (!vis[v[1][i].y])st[++top]=v[1][i].y;
		for (int i=1;i<=top;i++)vis[i]=1;
//		cout<<top<<endl;
		for (int i=1;i+1<=top;i+=2)
		{
			if (b[st[i]]!=-1||b[st[i+1]]!=-1)break;
			ans[st[i]]=ans[st[i+1]]=abs(a[st[i]]-a[st[i+1]])/2+m-max(a[st[i]],a[st[i+1]]);
			vis[i]=vis[i+1]=0;
		}
		for (int i=top;i-1>=1;i-=2)
		{
			if (b[st[i]]!=1||b[st[i-1]]!=1)break;
			ans[st[i]]=ans[st[i-1]]=abs(a[st[i]]-a[st[i-1]])/2+min(a[st[i]],a[st[i-1]]);
			vis[i]=vis[i-1]=0;
		}X=Y=0;
		for (int i=1;i<=top;i++)
			if (vis[i])
			{
				if (!X)X=i;
				else Y=i;
			}
		if (Y)ans[st[X]]=ans[st[Y]]=abs(2*m-a[st[X]]+a[st[Y]])/2;
	}for (int i=1;i<=n;i++)cout<<ans[i]<<' ';puts("");
}

signed main()
{
	WT{solve();}
	return 0;
}
/*
1
7 8
6 1 7 2 3 5 4
R L R L L L L
*/