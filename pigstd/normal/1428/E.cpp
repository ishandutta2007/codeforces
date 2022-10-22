#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int a[M],cnt[M],n,k,ans;

int f(int x,int y)
{
	return (y-(x%y))*(x/y)*(x/y)+(x%y)*(x/y+1)*(x/y+1);
}

struct node
{
	int pos,val;
};

bool operator <(const node &a,const node &b)
{
	return a.val>b.val;
}

priority_queue<node>q;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),cnt[i]=1,q.push((node){i,f(a[i],2)-a[i]*a[i]}),ans+=a[i]*a[i];
	for (int i=1;i<=k-n;i++)
	{
		node p=q.top();q.pop();
		ans+=p.val,cnt[p.pos]++;
		q.push((node){p.pos,f(a[p.pos],cnt[p.pos]+1)-f(a[p.pos],cnt[p.pos])});
	}
	cout<<ans<<endl;
	return 0;
}