#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
//#define x first
//#define y second
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

const int M=1e5+10;
int n,m,x,a[M],ans[M];
priority_queue<pair<int,int> >q;

signed main()
{
	WT
	{
		while(!q.empty())q.pop();
		n=read(),m=read(),x=read();
		for (int i=1;i<=n;i++)a[i]=read();YES
		for (int i=1;i<=m;i++)q.push(mp(0,i));
		for (int i=1;i<=n;i++)
		{
			int c=-q.top().first,p=q.top().second;q.pop();
			ans[i]=p,c+=a[i];q.push(mp(-c,p));
		}
		for (int i=1;i<=n;i++)cout<<ans[i]<<' ';puts("");
	}
	return 0;
}