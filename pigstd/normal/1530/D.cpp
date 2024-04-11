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
int n,ans,a[M],b[M],f[M];
vector<int>v1[M],v2[M],v3;

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){f[find(x)]=find(y);}

signed main()
{
	WT
	{
		n=read();ans=0;v3.clear();
		for (int i=1;i<=n;i++)f[i]=i,b[i]=0,v1[i].clear(),v2[i].clear();
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			if (v1[a[i]].size()==0)ans++;
			v1[a[i]].pb(i);
		}
		for (int i=1;i<=n;i++)
		{
			if (v1[i].size()==0)continue;
			int x=-1;
			for (int j=0;j<v1[i].size();j++)
				if (v1[v1[i][j]].size()==0){x=v1[i][j];break;}
			if (x==-1)x=v1[i][0];
			merge(x,i),b[x]=i;
		}
		for (int i=1;i<=n;i++)v2[find(i)].pb(i);
		for (int i=1;i<=n;i++)
			if (v2[i].size()==1)v3.pb(i);
		int f=(v3.size()==1);
		for (int i=1;i<=n;i++)
		{
			if (v2[i].size()<=1)continue;
			int X=-1,Y=-1;
			for (int j=0;j<v2[i].size();j++)
			{
				int x=v2[i][j];
				if (v1[x].size()==0)X=x;
				if (b[x]==0)Y=x;
			}
			if (X==-1)continue;
			if (f)b[Y]=v3[0],b[v3[0]]=X,f=0;
			else b[Y]=X;
		}
		if (v3.size()>1)
		{
			for (int i=0;i+1<v3.size();i++)b[v3[i]]=v3[i+1];
			b[v3[v3.size()-1]]=v3[0];
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++)cout<<b[i]<<' ';
		puts("");
	}
	return 0;
}