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

const int M=1e5+10;
int a[M],n;
queue<int>q[64];
vector<int>ans;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
		for (int j=60;j>=0;j--)
			if ((1ll<<j)&a[i]){q[j].push(i);break;}
	int now=0;
	for (int i=1;i<=n;i++)
	{
		int f=1;
		for (int j=0;j<=60;j++)
		{
			if ((1ll<<j)&now)continue;
			if (q[j].empty())continue;
			int x=q[j].front();q[j].pop();
			ans.pb(x);f=0;
			now^=a[x];break;
		}
		if (f)return puts("No"),0; 
	}puts("Yes");
	for (int i=0;i<ans.size();i++)
		cout<<a[ans[i]]<<' ';
	return 0;
}