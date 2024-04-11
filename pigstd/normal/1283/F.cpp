#include<bits/stdc++.h>
#define int long long
#define pb push_back
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

const int M=2e5+10;
int n,p[M],t[M];
priority_queue<int,vector<int>,greater<int> > q;

signed main()
{
	n=read();
	for (int i=1;i<n;i++)p[i]=read(),t[p[i]]++;
	cout<<p[1]<<endl;
	for (int i=1;i<=n;i++)if (!t[i])q.push(i);
	for (int i=n-1;i>=1;i--)
	{
		int u=q.top();q.pop();
		cout<<p[i]<<' '<<u<<endl;
		t[p[i]]--;if (!t[p[i]])q.push(p[i]);
	}
	return 0;
}
/*

*/