#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n,a[M],ans;
priority_queue<int> q;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (!q.empty()&&-q.top()<a[i])ans+=a[i]+q.top(),q.push(-a[i]),q.pop();
		q.push(-a[i]);
	}cout<<ans<<endl;
	return 0;
}