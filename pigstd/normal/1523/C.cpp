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

const int M=1010;
int a[M],st[M],top;
vector<int>ans[M];

signed main()
{
	WT
	{
		int n=read();top=0;
		for (int i=1;i<=n;i++)a[i]=read(),ans[i].clear();
		ans[1].pb(1);st[++top]=1;//puts("qwq");cout<<top<<endl;
		for (int i=2;i<=n;i++)
		{
			if (a[i]==1)
			{
				int x=st[top];//cout<<top<<endl;
				ans[i]=ans[x];ans[i].pb(1);
				st[++top]=i;
			}
			else
			{
				while(a[st[top]]!=a[i]-1)top--;
				int x=st[top--];ans[i]=ans[x];
				ans[i].pop_back();ans[i].pb(a[i]);
				st[++top]=i;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<ans[i].size();j++)
			{
				if (j)cout<<'.';
				cout<<ans[i][j];
			}puts("");
		}
	}
	return 0;
}
/*
1
9
1
1
1
2
2
1
2
1
2
*/