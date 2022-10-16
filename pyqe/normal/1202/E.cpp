#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long ln,n,aa[200069],sza[200069],as[200069],sq[2][200069];
vector<long long> a[200069];

struct trie
{
	long long c;
	trie *p[mm],*faf;
	
	void bd()
	{
		long long i;
		
		c=0;
		for(i=0;i<mm;i++)
		{
			p[i]=0;
		}
		faf=0;
	}
}
tr,*pst[200069];

bool csz(long long x,long long y)
{
	return sza[x]>sza[y];
}

int main()
{
	long long rr,i,j,ii,k,w,z=0;
	trie *p,*tg;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=1;i<=ln;i++)
	{
		aa[i]=s[i-1]-'a';
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		sza[i]=s.length();
		for(j=0;j<sza[i];j++)
		{
			a[i].push_back(s[j]-'a');
		}
		as[i]=i;
	}
	sort(as+1,as+n+1,csz);
	for(rr=0;rr<2;rr++)
	{
		tr.bd();
		for(i=1;i<=n;i++)
		{
			pst[i]=&tr;
		}
		for(i=1;i<=sza[as[1]];i++)
		{
			for(j=1;j<=n;j++)
			{
				k=as[j];
				if(sza[k]<i)
				{
					break;
				}
				w=a[k][i-1];
				if(!pst[k]->p[w])
				{
					tg=new trie;
					tg->bd();
					pst[k]->p[w]=tg;
					for(p=pst[k]->faf;p&&!p->p[w];p=p->faf);
					if(p)
					{
						tg->faf=p->p[w];
					}
					else
					{
						tg->faf=&tr;
					}
					tg->c=tg->faf->c;
				}
				pst[k]=pst[k]->p[w];
				pst[k]->c+=sza[k]==i;
			}
		}
		p=&tr;
		for(i=1;i<=ln;i++)
		{
			w=aa[i];
			for(;p&&!p->p[w];p=p->faf);
			if(p)
			{
				p=p->p[w];
			}
			else
			{
				p=&tr;
			}
			sq[rr][i]=p->c;
		}
		for(i=1;i<ln+1-i;i++)
		{
			swap(aa[i],aa[ln+1-i]);
			for(ii=0;ii<2;ii++)
			{
				swap(sq[ii][i],sq[ii][ln+1-i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<sza[i]-1-j;j++)
			{
				swap(a[i][j],a[i][sza[i]-1-j]);
			}
		}
	}
	for(i=2;i<=ln;i++)
	{
		z+=sq[0][i-1]*sq[1][i];
	}
	printf("%lld\n",z);
}