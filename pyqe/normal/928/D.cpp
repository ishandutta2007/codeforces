#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=26;
long long nn=0,ca[300069];

struct trie
{
	long long dh,c,ls;
	bool vtd;
	trie *p[mm];
	
	inline void bd(long long x)
	{
		long long i;
		
		dh=x;
		vtd=0;
		c=0;
		ls=0;
		for(i=0;i<mm;i++)
		{
			p[i]=0;
		}
	}
	void ins()
	{
		if(dh<nn)
		{
			long long l=ca[dh+1];
			
			if(!p[l])
			{
				p[l]=new trie;
				p[l]->bd(dh+1);
			}
			else
			{
				c-=p[l]->c;
			}
			p[l]->ins();
			c+=p[l]->c;
			ls=p[l]->ls;
		}
		else
		{
			c+=!vtd;
			vtd=1;
			ls=dh;
		}
	}
	pair<long long,bool> qr()
	{
		long long l=ca[dh+1];
		pair<long long,bool> tmp;
		
		if(dh<nn&&p[l])
		{
			tmp=p[l]->qr();
		}
		else
		{
			tmp={0,(vtd&&c==1)};
		}
		if(tmp.sc&&dh&&c==1)
		{
			tmp.fr=max(tmp.fr,ls-dh-1);
		}
		return tmp;
	}
}
tr;

int main()
{
	long long i,ln,z=0;
	string s;
	
	tr.bd(0);
	for(;getline(cin,s);)
	{
		ln=s.length();
		z+=ln+1;
		for(i=0;i<=ln;i++)
		{
			if(i<ln&&s[i]>='a'&&s[i]<='z')
			{
				nn++;
				ca[nn]=s[i]-'a';
			}
			else if(nn)
			{
				z-=tr.qr().fr;
				tr.ins();
				nn=0;
			}
		}
	}
	printf("%lld\n",z);
}