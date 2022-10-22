#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+1;
int n,a[N],head[N],cnt,mx=-0x7fffffff,tot;
map<int,int>q;
struct nd{int ne,to;}e[N];
void in(int x,int y){e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;}



int dfs(int i,int f)
{
	q[a[i]]--;q[a[i]-2]++;
	for(int tmp=head[i];tmp;tmp=e[tmp].ne)
	q[a[e[tmp].to]]--,q[a[e[tmp].to]-1]++;
	int ret=0;
	if(q[mx])ret=mx;
	else if(q[mx-1])ret=mx-1;
	else if(q[mx-2])ret=mx-2;
	q[a[i]]++;q[a[i]-2]--;
	for(int tmp=head[i];tmp;tmp=e[tmp].ne)
	q[a[e[tmp].to]]++,q[a[e[tmp].to]-1]--;
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1,x,y;i<n;++i)
	scanf("%d%d",&x,&y),in(x,y),in(y,x);
	for(int i=1;i<=n;++i)a[i]+=2;
	for(int i=1;i<=n;++i)q[a[i]]++;
	for(int i=1;i<=n;++i)mx=max(mx,a[i]);
	int ans=0x7fffffff;
	for(int i=1;i<=n;++i)ans=min(dfs(i,-1),ans);
	cout<<ans;
}