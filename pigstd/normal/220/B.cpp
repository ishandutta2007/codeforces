#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int p[M],n,q,a[M],id[M],ans[M],nowans;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct node
{
	int l,r,id;
}Q[M];

bool cmp(node a,node b)
{
	return id[a.l]<id[b.l]||(id[a.l]==id[b.l]&&id[a.r]<id[b.r]);
}

void add(int l)
{
	if (a[l]>1e5)return;
	if (p[a[l]]==a[l]-1)nowans++;
	if (p[a[l]]==a[l])nowans--;
	p[a[l]]++;
}

void del(int l)
{
	if (a[l]>1e5)return;
	if (p[a[l]]==a[l]+1)nowans++;
	if (p[a[l]]==a[l])nowans--;
	p[a[l]]--;
}

int main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	int bl=sqrt(n),sl=(n-1)/bl+1;
	for (int i=1;i<=sl;i++)
		for (int j=bl*(i-1)+1;j<=min(bl*i,n);j++)
			id[j]=i;
	for (int i=1;i<=q;i++)
		Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
	sort(Q+1,Q+1+q,cmp);int l=Q[1].l,r=l-1;
	for (int i=1;i<=q;i++)
	{
		while(r<Q[i].r)r++,add(r);
		while(r>Q[i].r)del(r),r--;
		while(l<Q[i].l)del(l),l++;
		while(l>Q[i].l)l--,add(l);
		ans[Q[i].id]=nowans;
	}
	for (int i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}