#include <bits/stdc++.h>

using namespace std;

const int sqn=316,mm=26;
int n,nn,aa[100069],qq[100069],sza[100069],ca[100069],faf[100069],ex[100069],fq[100069],ps[100069],vl[31600069],sq[100069];

struct trie
{
	int dh,pst;
	trie *p[mm];
	
	inline void bd(int x)
	{
		int i;
		
		dh=x;
		pst=0;
		for(i=0;i<mm;i++)
		{
			p[i]=0;
		}
	}
	void ins(int x)
	{
		if(dh<sza[x])
		{
			if(!p[ca[dh+1]])
			{
				p[ca[dh+1]]=new trie;
				p[ca[dh+1]]->bd(dh+1);
			}
			p[ca[dh+1]]->ins(x);
		}
		else
		{
			pst=x;
		}
	}
}
tr;

int main()
{
	int t,rr,i,j,ii,k,c;
	trie *p;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		aa[i]=s[i-1]-'a';
	}
	scanf("%d",&t);
	tr.bd(0);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%d",qq+rr);
		cin>>s;
		sza[rr]=s.length();
		for(i=1;i<=sza[rr];i++)
		{
			ca[i]=s[i-1]-'a';
		}
		if(sza[rr]>sqn)
		{
			faf[0]=-1;
			for(i=1;i<=sza[rr];i++)
			{
				for(j=faf[i-1];j+1&&ca[j+1]!=ca[i];j=faf[j]);
				faf[i]=j+1;
			}
			sq[rr]=n+1;
			c=0;
			nn=0;
			for(i=1;i<=n;i++)
			{
				for(;c+1&&(c+1>sza[rr]||ca[c+1]!=aa[i]);c=faf[c]);
				c++;
				if(c==sza[rr])
				{
					nn++;
					ex[nn]=i-sza[rr]+1;
					if(nn>=qq[rr])
					{
						sq[rr]=min(sq[rr],i-ex[nn+1-qq[rr]]+1);
					}
				}
			}
		}
		else
		{
			tr.ins(rr);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			p=&tr;
			for(j=1;j<=min(sqn,n+1-i);j++)
			{
				k=aa[i-1+j];
				if(!p->p[k])
				{
					break;
				}
				p=p->p[k];
				if(p->pst)
				{
					fq[p->pst]++;
					if(ii)
					{
						vl[ps[p->pst-1]+fq[p->pst]]=i;
					}
				}
			}
		}
		if(!ii)
		{
			for(rr=1;rr<=t;rr++)
			{
				ps[rr]=ps[rr-1]+fq[rr];
				fq[rr]=0;
			}
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		if(!sq[rr])
		{
			sq[rr]=n+1;
			for(i=ps[rr-1]+qq[rr];i<=ps[rr];i++)
			{
				sq[rr]=min(sq[rr],vl[i]-vl[i-qq[rr]+1]+sza[rr]);
			}
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		if(sq[rr]==n+1)
		{
			sq[rr]=-1;
		}
		printf("%d\n",sq[rr]);
	}
}