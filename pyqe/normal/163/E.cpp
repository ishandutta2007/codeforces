#include <bits/stdc++.h>

using namespace std;

long long n,ln[100069],nn=0,pst[1000069],sbt[1000069],fw[1000069],fi;
vector<long long> a[100069],al[1000069];
bitset<100069> spc;

struct trie
{
	long long od;
	trie *p[26],*faf;
	
	void bd()
	{
		long long i;
		
		for(i=0;i<26;i++)
		{
			p[i]=0;
		}
		faf=0;
		nn++;
		od=nn;
	}
}
tr;

void ud(long long x,long long w)
{
	for(fi=x;fi<=nn;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	nn++;
	pst[x]=nn;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		bd(l);
		sbt[x]+=sbt[l];
	}
}

int main()
{
	long long t,rr,i,j,k,l,sz,mx=0,e,z;
	trie *ia[100069],*tmp;
	char ch;
	string s;
	
	scanf("%lld%lld",&t,&n);
	tr.bd();
	for(i=1;i<=n;i++)
	{
		cin>>s;
		ln[i]=s.length();
		mx=max(mx,ln[i]);
		for(j=0;j<ln[i];j++)
		{
			a[i].push_back(s[j]-'a');
		}
		ia[i]=&tr;
	}
	for(j=0;j<mx;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(j<ln[i])
			{
				k=a[i][j];
				if(!ia[i]->p[k])
				{
					ia[i]->p[k]=new trie;
					ia[i]->p[k]->bd();
					for(tmp=ia[i]->faf;tmp&&!tmp->p[k];tmp=tmp->faf);
					if(tmp)
					{
						tmp=tmp->p[k];
					}
					else
					{
						tmp=&tr;
					}
					ia[i]=ia[i]->p[k];
					ia[i]->faf=tmp;
					al[ia[i]->faf->od].push_back(ia[i]->od);
				}
				else
				{
					ia[i]=ia[i]->p[k];
				}
			}
		}
	}
	nn=0;
	bd(1);
	for(i=1;i<=n;i++)
	{
		k=ia[i]->od;
		ud(pst[k],1);
		ud(pst[k]+sbt[k],-1);
		spc[i]=1;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c",&ch);
		if(ch!='?')
		{
			scanf("%lld",&k);
			e=ch=='+';
			l=ia[k]->od;
			ud(pst[l],e-spc[k]);
			ud(pst[l]+sbt[l],spc[k]-e);
			spc[k]=e;
		}
		else
		{
			cin>>s;
			sz=s.length();
			tmp=&tr;
			z=0;
			for(i=0;i<sz;i++)
			{
				k=s[i]-'a';
				for(;tmp&&!tmp->p[k];tmp=tmp->faf);
				if(tmp)
				{
					tmp=tmp->p[k];
				}
				else
				{
					tmp=&tr;
				}
				z+=qr(pst[tmp->od]);
			}
			printf("%lld\n",z);
		}
	}
}