#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

set<int> s[100001];
int n,q,x,ord,y,cnt,val[100001];
long long ans[100001],tree[100001];

struct node
{
	int pre,val,now,ord;
}a[1000001],b[1000001];

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

void ins(int x,int pos)
{
	s[x].insert(pos);
	set<int>::iterator it=s[x].find(pos),itt=it; itt++;
	int pre=0,suf=0;
	if (it!=s[x].begin()) it--,pre=*it;
	if (itt!=s[x].end()) suf=*itt;
	if (pre) a[++cnt].pre=pre,a[cnt].val=pos-pre,a[cnt].now=pos,a[cnt].ord=0;
	if (suf) a[++cnt].pre=pos,a[cnt].val=suf-pos,a[cnt].now=suf,a[cnt].ord=0;
	if (pre&&suf) a[++cnt].pre=pre,a[cnt].val=pre-suf,a[cnt].now=suf,a[cnt].ord=0;
}

void del(int x,int pos)
{
	set<int>::iterator it=s[x].find(pos),itt=it; itt++;
	int pre=0,suf=0;
	if (it!=s[x].begin()) it--,pre=*it;
	if (itt!=s[x].end()) suf=*itt;
	if (pre) a[++cnt].pre=pre,a[cnt].val=pre-pos,a[cnt].now=pos,a[cnt].ord=0;
	if (suf) a[++cnt].pre=pos,a[cnt].val=pos-suf,a[cnt].now=suf,a[cnt].ord=0;
	if (pre&&suf) a[++cnt].pre=pre,a[cnt].val=suf-pre,a[cnt].now=suf,a[cnt].ord=0;
	s[x].erase(pos);
}

void add(int x,long long val)
{
	for (int i=x; i<=n; i+=(i&-i)) tree[i]+=val;
}

long long query(int x)
{
	long long ans=0;
	for (int i=x; i; i-=(i&-i)) ans+=tree[i];
	return ans;
}

void solve(int l,int r)
{
	if (l>=r) return;
	int mid=(l+r)>>1;
	solve(l,mid); solve(mid+1,r);
	int t1=l,t2=mid+1,t=l;
	while (t1<=mid||t2<=r)
	{
		if (t2>r||t1<=mid&&a[t1].now<=a[t2].now)
		{
			b[t++]=a[t1++];
			if (a[t1-1].ord) continue;
			add(a[t1-1].pre,a[t1-1].val);
		} else
		{
			b[t++]=a[t2++];
			if (!a[t2-1].ord) continue;
			ans[a[t2-1].ord]+=query(a[t2-1].now)-query(a[t2-1].pre-1);
		}
	}
	for (int i=l; i<=mid; i++) 
		if (!a[i].ord) add(a[i].pre,-a[i].val);
	for (int i=l; i<=r; i++) a[i]=b[i];
}

int main()
{
	n=read(); q=read(); cnt=0;
	for (int i=1; i<=n; i++) val[i]=read(),ins(val[i],i);
	for (int i=1; i<=q; i++)
	{
		ord=read(); x=read(); y=read();
		if (ord==1)
		{
			del(val[x],x);
			val[x]=y;
			ins(val[x],x);
			ans[i]=-1;
		}
		else a[++cnt].pre=x,a[cnt].val=0,a[cnt].now=y,a[cnt].ord=i,ans[i]=0;
	}
	memset(tree,0,sizeof(tree));
	solve(1,cnt);
	for (int i=1; i<=q; i++)
		if (ans[i]!=-1) printf("%I64d\n",ans[i]);
	return 0;
}