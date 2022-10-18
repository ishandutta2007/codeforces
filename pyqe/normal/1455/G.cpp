#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n=0,d,nn=0,dsu[200069],cc[200069],lz[200069],sk[200069],inf=1e18;
multiset<pair<long long,long long>> vl[200069];
multiset<long long> ms[200069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}
void bd()
{
	n++;
	dsu[n]=n;
	nn++;
	sk[nn]=n;
}

void ins(long long ix,long long x,long long w)
{
	multiset<pair<long long,long long>>::iterator it;
	
	ix=fd(ix);
	w-=lz[ix];
	it=vl[ix].lower_bound({x,-inf});
	if(it!=vl[ix].end()&&it->fr==x)
	{
		if(it->sc<=w)
		{
			return;
		}
		else
		{
			ms[ix].erase(ms[ix].find(it->sc));
			vl[ix].erase(it);
		}
	}
	vl[ix].insert({x,w});
	ms[ix].insert(w);
	cc[ix]++;
}

void ers(long long ix,long long x)
{
	multiset<pair<long long,long long>>::iterator it;
	
	ix=fd(ix);
	it=vl[ix].lower_bound({x,-inf});
	if(it!=vl[ix].end()&&it->fr==x)
	{
		ms[ix].erase(ms[ix].find(it->sc));
		vl[ix].erase(it);
	}
}

long long qr(long long ix,long long x)
{
	multiset<pair<long long,long long>>::iterator it;
	
	ix=fd(ix);
	it=vl[ix].lower_bound({x,-inf});
	if(it!=vl[ix].end()&&it->fr==x)
	{
		return it->sc+lz[ix];
	}
	else
	{
		return inf;
	}
}

void jo(long long x,long long y)
{
	multiset<pair<long long,long long>>::iterator it;
	
	x=fd(x);
	y=fd(y);
	if(cc[x]<cc[y])
	{
		swap(x,y);
	}
	for(it=vl[y].begin();it!=vl[y].end();it++)
	{
		ins(x,it->fr,it->sc+lz[y]);
	}
	cc[x]+=cc[y];
	dsu[y]=x;
}

int main()
{
	long long t,rr,k,l,w;
	string s;
	
	scanf("%lld%lld",&t,&d);
	bd();
	ins(1,0,0);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		if(s[0]=='s')
		{
			scanf("%lld%lld",&k,&l);
			w=*ms[fd(sk[nn])].begin()+lz[fd(sk[nn])];
			lz[fd(sk[nn])]+=l;
			if(k!=d)
			{
				ins(sk[nn],k,w);
			}
		}
		else if(s[0]=='i')
		{
			scanf("%lld",&k);
			bd();
			ins(sk[nn],k,qr(sk[nn-1],k));
			ers(sk[nn-1],k);
		}
		else
		{
			jo(sk[nn],sk[nn-1]);
			nn--;
		}
	}
	printf("%lld\n",*ms[fd(1)].begin()+lz[fd(1)]);
}