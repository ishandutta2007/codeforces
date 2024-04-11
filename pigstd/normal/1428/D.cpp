#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int n,a[M],sum;
int ans[M][2];
// 
int last[M];

set<int>h;set<int>l;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	int now=0;
	for (int i=n;i>=1;i--)
	{
		if (a[i]==3)
		{
			if(l.size()==0){puts("-1");return 0;}
			now++;int k=*l.begin();
			ans[i][0]=ans[k][1]=now;
			l.erase(k);
			l.insert(i);
			h.erase(ans[k][0]);
//			cout<<now<<' ';
		}
		if (a[i]==1)
		{
			ans[i][0]=++now;
			l.insert(i),h.insert(now);
			ans[i][0]=now;
			last[now]=i;
//			cout<<now<<' ';
		}
		if (a[i]==2)
		{
			if (h.size()==0){puts("-1");return 0;}
			int k=*h.begin();
			ans[i][0]=k;
			l.erase(last[k]);
			l.insert(i);
			h.erase(h.begin());
//			cout<<now<<' ';
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i][0])sum++;
		if(ans[i][1])sum++;
	}
	cout<<sum<<endl;
	for (int i=1;i<=n;i++)
	{
		if (ans[i][0])cout<<n-ans[i][0]+1<<' '<<i<<endl;
		if (ans[i][1])cout<<n-ans[i][1]+1<<' '<<i<<endl;
	}
	return 0;
}

//stO sjy Orz
//rp++