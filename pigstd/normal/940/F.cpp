#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;

struct change
{
	int p,c;
}C[M];int cnt1;

struct query
{
	int l,r,t,id,ans;
}Q[M];int cnt2;

int n,q,t,bl,a[M],p2[M],ans;

int p1[M];map<int,int> tt;int cnt;

int id(int k){return k/bl;}

bool cmp1(query a,query b)
{return id(a.l)<id(b.l)||(id(a.l)==id(b.l)&&id(a.r)<id(b.r))||(id(a.l)==id(b.l)&&id(a.r)==id(b.r)&&id(a.t)<id(b.t));}

bool cmp2(query a,query b){return a.id<b.id;}

void add(int k)
{
	p2[p1[k]]--;
	p1[k]++;
	p2[p1[k]]++;
}

void del(int k)
{
	p2[p1[k]]--;
	p1[k]--;
	p2[p1[k]]++;
}

void upd(int p,int t)
{
	if (C[t].p<=Q[p].r&&C[t].p>=Q[p].l)
		del(a[C[t].p]),add(C[t].c);
	swap(a[C[t].p],C[t].c);
}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (tt[a[i]]==0)tt[a[i]]=++cnt;
		a[i]=tt[a[i]];
	}
	bl=pow(n,0.666666);
	for (int i=1;i<=q;i++)
	{
		int op;cin>>op;
		if (op==1)
		{
			cnt2++;
			cin>>Q[cnt2].l>>Q[cnt2].r;Q[cnt2].id=i,Q[cnt2].t=cnt1;
		}
		else
		{
			cnt1++;
			cin>>C[cnt1].p>>C[cnt1].c;
			if (tt[C[cnt1].c]==0)tt[C[cnt1].c]=++cnt;
			C[cnt1].c=tt[C[cnt1].c];
		}
	}
	sort(Q+1,Q+cnt2+1,cmp1);
	int l=1,r=0,now=0;
	for (int i=1;i<=cnt2;i++)
	{
		while(l>Q[i].l)l--,add(a[l]);
		while(l<Q[i].l)del(a[l]),l++;
		while(r>Q[i].r)del(a[r]),r--;
		while(r<Q[i].r)r++,add(a[r]);
		while(now<Q[i].t)now++,upd(i,now);
		while(now>Q[i].t)upd(i,now),now--;
		for (int j=1;j<=n;j++)
			if (p2[j]==0){Q[i].ans=j;break;}
	}
	sort(Q+1,Q+1+cnt2,cmp2);
	for (int i=1;i<=cnt2;i++)cout<<Q[i].ans<<endl;
	return 0;
}