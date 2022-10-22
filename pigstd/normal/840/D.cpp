#include<bits/stdc++.h>
using namespace std;

const int M=3e5+10;
int n,m,a[M],t[M],ans[M],k,bl;
struct query
{
	int l,r,id,k;
}Q[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int id(int k){return (k-1)/bl;}
bool cmp(query a,query b)
{
	return id(a.l)<id(b.l)||(id(a.l)==id(b.l)&&id(a.r)<id(b.r));
}

void add(int k){t[a[k]]++;}
void del(int k){t[a[k]]--;}

typedef std::mt19937  Random_mt19937;
Random_mt19937  rnd(time(0));

int main()
{
	n=read(),m=read();bl=sqrt(n);
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=m;i++)Q[i].l=read(),Q[i].r=read(),Q[i].k=read(),Q[i].id=i;
	sort(Q+1,Q+1+m,cmp);int l=1,r=0;
	for (int i=1;i<=m;i++)
	{
		while(r<Q[i].r)add(++r);
		while(l>Q[i].l)add(--l);
		while(r>Q[i].r)del(r--);
		while(l<Q[i].l)del(l++);int s=(Q[i].r-Q[i].l+1)/Q[i].k;
		for (int sjy_AK_IOI=1;sjy_AK_IOI<=200;sjy_AK_IOI++)
		{
			int p=rnd()%(Q[i].r-Q[i].l+1)+Q[i].l;
			if (t[a[p]]>s)ans[Q[i].id]=ans[Q[i].id]==0?a[p]:min(ans[Q[i].id],a[p]);
		}
	}
	for (int i=1;i<=m;i++)
		cout<<(ans[i]==0?-1:ans[i])<<endl;
	return 0;
}