#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7,P=998244353;

int n,q;

typedef pair<int,int> node;
#define fs first
#define sd second
#define mp make_pair

int cnt;

struct T{
	int ls,rs,l,r;
	ll sum,tag1,tag2;
}t[N*2+1];

void update(int x)
{
	t[x].sum=(t[t[x].ls].sum+t[t[x].rs].sum)%P;
}

void pushdown(int x)
{
	t[t[x].ls].sum=t[t[x].ls].sum*t[x].tag2%P;
	t[t[x].ls].sum=(t[t[x].ls].sum+t[x].tag1*(t[t[x].ls].r-t[t[x].ls].l+1)%P)%P; 
	t[t[x].ls].tag1=(t[t[x].ls].tag1*t[x].tag2%P+t[x].tag1)%P;
	t[t[x].ls].tag2=(t[t[x].ls].tag2*t[x].tag2)%P;
	t[t[x].rs].sum=t[t[x].rs].sum*t[x].tag2%P;
	t[t[x].rs].sum=(t[t[x].rs].sum+t[x].tag1*(t[t[x].rs].r-t[t[x].rs].l+1)%P)%P; 
	t[t[x].rs].tag1=(t[t[x].rs].tag1*t[x].tag2%P+t[x].tag1)%P;
	t[t[x].rs].tag2=(t[t[x].rs].tag2*t[x].tag2)%P;
	t[x].tag1=0,t[x].tag2=1;
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	t[x].tag2=1;
	if(l==r)
		return x;
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	return x;
}

void cg1(int x,int l,int r,ll w)
{
	pushdown(x);
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].sum=(t[x].sum+1ll*w*(t[x].r-t[x].l+1)%P)%P;
		t[x].tag1=(t[x].tag1+w)%P; 
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		cg1(t[x].ls,l,r,w);
	if(r>mid)
		cg1(t[x].rs,l,r,w);
	update(x);
}

void cg2(int x,int l,int r,ll w)
{
	pushdown(x);
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].sum=(t[x].sum*w)%P;
		t[x].tag1=(t[x].tag1*w)%P; 
		t[x].tag2=(t[x].tag2*w)%P;
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		cg2(t[x].ls,l,r,w);
	if(r>mid)
		cg2(t[x].rs,l,r,w);
	update(x);
}

ll query(int x,int l,int r)
{
	pushdown(x);
	if(l<=t[x].l&&t[x].r<=r)
		return t[x].sum;
	int mid=(t[x].l+t[x].r)>>1;
	ll ret=0;
	if(l<=mid)
		ret=(ret+query(t[x].ls,l,r))%P;
	if(r>mid)
		ret=(ret+query(t[x].rs,l,r))%P;
	return ret;
}

multiset<node>s[N];

multiset<node>::iterator pr,sf,it;

vector<node>st;

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		s[i].insert(mp(0,0));
		s[i].insert(mp(n+1,n+1));
	}
	build(1,n);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int l,r,v;
			scanf("%d%d%d",&l,&r,&v);
			pr=--s[v].lower_bound(mp(l,0));
			sf=--s[v].lower_bound(mp(r+1,0));
			if((*pr).sd<l)
				++pr;
			if((*pr).fs>r)
			{
				cg1(1,l,r,1);
				s[v].insert(mp(l,r));
			}
			else if((*pr).fs<=l&&r<=(*pr).sd)
				cg2(1,l,r,2);
			else
			{
				st.clear();
				while(pr!=sf)
					st.push_back(*pr),pr++;
				st.push_back(*sf);
				for(int i=0;i<st.size();i++)
					cg2(1,max(st[i].fs,l),min(st[i].sd,r),2);
				int tmpl,tmpr;
				tmpl=l;
				for(int i=0;i<st.size();i++)
				{
					tmpr=st[i].fs-1;
					if(tmpl<=tmpr)
						cg1(1,tmpl,tmpr,1);
					tmpl=st[i].sd+1;
				} 
				if(tmpl<=r)
					cg1(1,tmpl,r,1);
				tmpl=min(st[0].fs,l),tmpr=max(st[st.size()-1].sd,r);
				for(int i=0;i<st.size();i++)
					s[v].erase(s[v].find(st[i]));
				s[v].insert(mp(tmpl,tmpr));
			}
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,l,r));
		}
	}
}