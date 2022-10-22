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

const int M=1010;
int n,m1,m2,f1[M],f2[M];
vector<pair<int,int> >ans;

int find1(int x){return f1[x]==x?x:f1[x]=find1(f1[x]);}
int find2(int x){return f2[x]==x?x:f2[x]=find2(f2[x]);}

signed main()
{
	n=read(),m1=read(),m2=read();
	for (int i=1;i<=n;i++)f1[i]=f2[i]=i;
	for (int i=1;i<=m1;i++)
	{
		int u=read(),v=read();
		f1[find1(u)]=find1(v);
	}
	for (int i=1;i<=m2;i++)
	{
		int u=read(),v=read();
		f2[find2(u)]=find2(v);
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (find1(i)!=find1(j)&&find2(i)!=find2(j))
				f1[find1(i)]=find1(j),f2[find2(i)]=find2(j),ans.pb(mp(i,j));
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
		cout<<ans[i].x<<' '<<ans[i].y<<endl;
	return 0;
}