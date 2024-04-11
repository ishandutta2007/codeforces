#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0;
multiset<pair<long long,pair<long long,long long>>> ms,ms2;

void ins(long long p,long long x,long long w)
{
	ms.insert({p,{x,w}});
	ms2.insert({w,{p,x}});
	nn++;
}

void ers(long long p,long long x,long long w)
{
	ms.erase(ms.find({p,{x,w}}));
	ms2.erase(ms2.find({w,{p,x}}));
	nn--;
}

int main()
{
	long long i,k,l=-1,w=0,c=0,p,k2,w2,p2,k3,w3,p3,e,e2;
	multiset<pair<long long,pair<long long,long long>>>::iterator it;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n+1;i++)
	{
		if(i<=n)
		{
			k=s[i-1]-'a';
		}
		else
		{
			k=-1;
		}
		if(l+1&&l!=k)
		{
			if(ms.empty()||i==n+1)
			{
				c*=2;
			}
			ins(nn,l,c);
			c=0;
		}
		l=k;
		c++;
	}
	for(;nn>1;)
	{
		w=ms2.begin()->fr;
		p=ms2.begin()->sc.fr;
		k=ms2.begin()->sc.sc;
		it=ms.find({p,{k,w}});
		if(it==ms.begin())
		{
			if(next(it)!=ms.end())
			{
				p2=next(it)->fr;
				k2=next(it)->sc.fr;
				w2=next(it)->sc.sc;
				ers(p2,k2,w2);
				ins(p2,k2,max(w2-(w+1)/2*2,0ll)*2+(w+1)/2*2);
			}
		}
		else if(next(it)==ms.end())
		{
			if(it!=ms.begin())
			{
				p2=prev(it)->fr;
				k2=prev(it)->sc.fr;
				w2=prev(it)->sc.sc;
				ers(p2,k2,w2);
				ins(p2,k2,max(w2-(w+1)/2*2,0ll)*2+(w+1)/2*2);
			}
		}
		else
		{
			p2=prev(it)->fr;
			k2=prev(it)->sc.fr;
			w2=prev(it)->sc.sc;
			p3=next(it)->fr;
			k3=next(it)->sc.fr;
			w3=next(it)->sc.sc;
			if(k2==k3)
			{
				e=prev(it)==ms.begin();
				e2=next(next(it))==ms.end();
				ers(p2,k2,w2);
				ers(p3,k3,w3);
				ins(p2,k2,max(w2-(w+1)/2*2,0ll)*(1+e2)+max(w3-(w+1)/2*2,0ll)*(1+e)+(w+1)/2*2);
			}
		}
		ers(p,k,w);
	}
	printf("%lld\n",(w+1)/2);
}