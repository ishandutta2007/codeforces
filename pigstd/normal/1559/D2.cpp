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

const int M=1e5+10;
int n,m1,m2,f1[M],f2[M];
vector<pair<int,int> >ans;
vector<int>v1,v2;

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
	for (int i=2;i<=n;i++)
		if (find1(i)!=find1(1)&&find2(i)!=find2(1))
			ans.pb(mp(1,i)),f1[find1(i)]=find1(1),f2[find2(i)]=find2(1);
	for (int i=1;i<=n;i++)
		if (find1(i)!=find1(1))v1.pb(i),f1[find1(i)]=find1(1);
		else if (find2(i)!=find2(1))v2.pb(i),f2[find2(i)]=find2(1);
	for (int i=0;i<v1.size()&&i<v2.size();i++)
		ans.pb(mp(v1[i],v2[i]));
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
		cout<<ans[i].x<<' '<<ans[i].y<<endl;
	return 0;
}