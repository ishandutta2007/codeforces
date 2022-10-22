#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int n,m,p,k,a[M],h[M],tl,tr,ans,c[M];

struct node
{
    int num,p;
    bool operator <(const node &q)const
    {return q.num<num;}
};

bool check(int r)
{
    priority_queue<node>q;
    for (int i=1;i<=n;i++)
    {
        if (h[i]+m*a[i]<=r)continue;
        q.push((node){r/a[i],i});c[i]=0;
    }
    int cnt=0;
    for (int i=1;i<=m&&!q.empty();i++)
        for (int j=1;!q.empty()&&j<=k;j++)
        {
            if (q.top().num<i)return 0;
            int x=q.top().p;q.pop();c[x]++;
            int w=(r+c[x]*p)/a[x];
            if (w<m)q.push((node){w,x});
            ++cnt;
        }
    for (int i=1;i<=n;i++)
    {
        int w=r+c[i]*p-m*a[i];
        if (w>=h[i])continue;
        cnt+=(h[i]-w-1)/p+1;
    }
    return cnt<=m*k;
}

signed main()
{
	n=read(),m=read(),k=read(),p=read();
	for (int i=1;i<=n;i++)
		h[i]=read(),a[i]=read(),
		tl=max(tl,a[i]),tr=max(tr,h[i]+m*a[i]);
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid))
			ans=Mid,tr=Mid-1;
		else tl=Mid+1;
	}
	cout<<ans<<endl;
    return 0;
}