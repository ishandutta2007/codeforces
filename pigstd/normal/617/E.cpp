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

const int M=2e6+10;
const int N=1e5+10;
int n,q,k,cnt,nowans,p[M],id[M],ans[M],Ans[M],a[M];
map<int,int>t;

struct node
{
	int l,r,id;
}Q[N];

bool cmp(node a,node b)
{
	return id[a.l]<id[b.l]||(id[a.l]==id[b.l]&&id[a.r]<id[b.r]);
}

void add(int a){nowans+=p[a^k],p[a]++;}

void del(int a){p[a]--,nowans-=p[a^k];}

bool cmp2(node a,node b){return a.id<b.id;}

signed main()
{
//	freopen("P1494_1.in","r",stdin);
//	freopen("qwq.txt","w",stdout);
	n=read(),q=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),a[i]^=a[i-1];
	}int bl=sqrt(n),sl=(n-1)/bl+1;
	for (int i=1;i<=sl;i++)
	{
		int L=(i-1)*bl+1,R=min(n,i*bl);
		for (int j=L;j<=R;j++)id[j]=i;
	}
	for (int i=1;i<=q;i++)
		Q[i].id=i,Q[i].l=read()-1,Q[i].r=read();
	sort(Q+1,Q+1+q,cmp);
	int l=1,r=0;
	for (int i=1;i<=q;i++)
	{
		while(l>Q[i].l)l--,add(a[l]);
		while(l<Q[i].l)del(a[l]),l++;
		while(r<Q[i].r)r++,add(a[r]);
		while(r>Q[i].r)del(a[r]),r--;
		ans[Q[i].id]=nowans;
	}
	for (int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}