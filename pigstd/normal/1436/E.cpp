#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int M=1e5+10;
int n,bl,a[M],b[M],ans=1e9;
bool vis[M];
vector<int>v[M];

struct query
{
	int l,r,i;
}q[M<<1];

int id(int k){return (k-1)/bl+1;}
int r(int k){return min(n,bl*k);}
int l(int k){return bl*(k-1)+1;}
bool cmp(query a,query b){return id(a.l)<id(b.l)||(id(a.l)==id(b.l)&&id(a.r)<id(b.r));}

struct segment_tree// 
{
	int b[M],s[M];
	void add(int k)
	{
		if (b[k]==0)
			s[id(k)]++;
		b[k]++;
//		cout<<k<<' '<<1<<endl;
	}
	void del(int k)
	{
		if (b[k]==1)s[id(k)]--;
		b[k]--;
//		cout<<k<<' '<<-1<<endl;
	}
	int query()
	{
		for (int i=1;i<=id(n);i++)
		{
			if (s[i]==r(i)-l(i)+1)continue;
			for (int j=l(i);j<=r(i);j++)
				if (b[j]==0)return j;
		}return n+1;
	}
//	void Memset()
//	{
//		memset(b,0,sizeof(b));
//		memset(s,0,sizeof(s));
//	}
}T;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void add(int k)
{
	T.add(k);
}

void del(int k)
{
	T.del(k);
}

signed main()
{
	n=read();bl=sqrt(n);int cnt=0;
	for (int i=1;i<=n;i++)a[i]=read(),v[a[i]].pb(i);
	for (int i=1;i<=n+2;i++)
	{
		b[0]=0;
		for (int j=0;j<v[i].size();j++)
			b[j+1]=v[i][j];
		b[v[i].size()+1]=n+1;
		for (int j=1;j<=v[i].size()+1;j++)
			if (b[j]-1>=b[j-1]+1)
				q[++cnt].l=b[j-1]+1,q[cnt].r=b[j]-1,q[cnt].i=i;
	}
	sort(q+1,q+1+cnt,cmp);
	int l=1,r=0;
	for (int j=1;j<=cnt;j++)
	{
		while(r<q[j].r)add(a[++r]);
		while(l>q[j].l)add(a[--l]);
		while(r>q[j].r)del(a[r--]);
		while(l<q[j].l)del(a[l++]);
		if (T.query()==q[j].i)
			vis[q[j].i]=1;
	}
	for (int i=1;i<=n+2;i++)
		if (!vis[i])return printf("%lld",i),0;
	return 0;
}