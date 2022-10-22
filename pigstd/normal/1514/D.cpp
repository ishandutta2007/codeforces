#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=3e5+10;
int n,q,bl,a[M],lans,nans,ans[M],ql[M],qr[M];
int t[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct query
{
	int l,r,k;
}Q[M];int cnt;

int id(int x){return (x-1)/bl+1;}
int L(int x){return bl*(x-1)+1;}
int R(int x){return min(n,bl*x);}

bool cmp(query a,query b){return id(a.l)<id(b.l)||(id(a.l)==id(b.l)&&id(a.r)<id(b.r));}

void add(int k){t[a[k]]++,nans=max(nans,t[a[k]]);}

/*
12 2
15 9 3 15 9 3 3 8 16 9 3 17
1 12
4 8
*/

signed main()
{
	n=read(),q=read();bl=sqrt(n);
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();ql[i]=l,qr[i]=r;
		if (id(l)==id(r))
		{
			for (int j=l;j<=r;j++)
				t[a[j]]++,ans[i]=max(ans[i],t[a[j]]);
			for (int j=l;j<=r;j++)
				t[a[j]]--;
		}
		else Q[++cnt].l=l,Q[cnt].r=r,Q[cnt].k=i; 
	}
	sort(Q+1,Q+1+cnt,cmp);int r=0,l=1;
	for (int i=1,ll=0,rr=0;i<=cnt;i++)
	{
		if (ll!=id(Q[i].l))
		{
			rr=ll=id(Q[i].l);l=R(ll)+1,r=R(ll);
			memset(t,0,sizeof(t));nans=0;
		}
		if (rr!=id(Q[i].r)-1)
		{
			int kr=rr;
			rr=id(Q[i].r)-1;
			for (int j=R(kr)+1;j<=R(rr);j++)add(j);
			r=R(rr);
		}
		lans=nans;int RR=r,LL=l;
		while(r<Q[i].r)add(++r);
		while(l>Q[i].l)add(--l);
		ans[Q[i].k]=nans;
		for (int i=RR+1;i<=r;i++)t[a[i]]--;
		for (int i=l;i<=LL-1;i++)t[a[i]]--;
		nans=lans;l=LL,r=RR;
	}
	for (int i=1;i<=q;i++)
	{
		if (ans[i]<=(qr[i]-ql[i]+2)/2){puts("1");continue;}
		cout<<ans[i]-(qr[i]-ql[i]+1-ans[i])<<endl;
	}
	return 0;
}