#include<bits/stdc++.h>
//#define int long long
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

const int M=1010;
int n,vis[M],vis2[M],f[M],u[M],v[M],ans,X,Y,Sum;
vector<pair<int,int> >e[M];
vector<int>V,V2;

void dfs(int u)
{
	if (Sum==0)return;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;
		if (Sum==0)break;
		if (!vis2[to]&&f[w])
			Sum--,V.pb(w),V2.pb(to),vis2[to]=1,dfs(to);
	}
}

void solve()
{
//	assert(k<=20);
	vector<int>vv;Sum=0;
	for (int i=1;i<=n;i++)
		vis[i]=vis2[i]=0;
	for (int i=1;i<n;i++)
		if (f[i])
			vis[u[i]]=vis[v[i]]=1,Sum++;
	for (int i=1;i<=n;i++)
		if (vis[i])vv.pb(i);
	if (vv.size()==2)
	{
		X=vv[0],Y=vv[1];
		return;
	}int tmp=Sum;Sum=Sum/2; V2.clear();V.clear();
	for (int i=0;i<vv.size();i++)
		if (!vis2[vv[i]]&&Sum!=0)
			vis2[vv[i]]=1,V2.pb(vv[i]),dfs(vv[i]);
	cout<<"? "<<V2.size()<<' ';
	for (int i=0;i<V2.size();i++)
		cout<<V2[i]<<' ';cout<<endl;
	int x;cin>>x;
	if (x==ans)
	{
		memset(f,0,sizeof(f));
		for (int i=0;i<V.size();i++)
			f[V[i]]=1;solve();
	}
	else
	{
		for (int i=0;i<V.size();i++)
			f[V[i]]=0;solve();
	}
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read();f[i]=1;
		e[u[i]].pb(mp(v[i],i)),
		e[v[i]].pb(mp(u[i],i));
	}cout<<"? "<<n<<' ';
	for (int i=1;i<=n;i++)
		cout<<i<<' ';cout<<endl;
	cin>>ans;solve();
	cout<<"! "<<X<<' '<<Y<<endl;
	return 0;
}
//
//