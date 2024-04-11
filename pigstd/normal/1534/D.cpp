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

const int M=2010;
int n,a[M],b[M],c;
pair<int,int>ans[M];
vector<int>cnt[2];

signed main()
{
	n=read();
	cout<<"? 1"<<endl;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]&1].pb(i);
	}
	if (cnt[0].size()>cnt[1].size())swap(cnt[0],cnt[1]);
	for (int i=0;i<cnt[0].size();i++)
	{
		int x=cnt[0][i];
		if (x==1)
		{
			for (int j=1;j<=n;j++)
				if (a[j]==1)ans[++c]=mp(x,j);
		}
		else
		{
			cout<<"? "<<x<<endl;
			for (int j=1;j<=n;j++)
			{
				cin>>b[j];
				if (b[j]==1)ans[++c]=mp(x,j); 
			}
		}
	}puts("!");
	for (int i=1;i<=c;i++)
		cout<<ans[i].x<<' '<<ans[i].y<<endl;
	return 0;
}