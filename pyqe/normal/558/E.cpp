#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],p;
array<long long,26> rs;

long long md(long long l,long long r)
{
	return (l+r)/2;
}

struct segtree
{
	long long l,r,lz;
	array<long long,26> fq;
	segtree *p1,*p2;
	
	array<long long,26> mrg(array<long long,26> x,array<long long,26> y)
	{
		long long i;
		array<long long,26> k;
		
		for(i=0;i<26;i++)
		{
			k[i]=x[i]+y[i];
		}
		return k;
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			long long i;
			
			for(i=0;i<26;i++)
			{
				fq[i]=0;
			}
			fq[a[l]]=1;
		}
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(l,md(l,r));
			p2->bd(md(l,r)+1,r);
			fq=mrg(p1->fq,p2->fq);
		}
	}
	void blc()
	{
		if(!lz)
		{
			return;
		}
		long long k=0,ln,i;
		
		if(lz==2)
		{
			swap(p1,p2);
		}
		ln=p1->r-p1->l+1;
		for(i=0;i<26;i++)
		{
			if(k<ln)
			{
				p1->fq[i]=fq[i];
				p2->fq[i]=0;
				k+=fq[i];
				if(k>=ln)
				{
					p1->fq[i]-=k-ln;
					p2->fq[i]+=k-ln;
				}
			}
			else
			{
				p2->fq[i]=fq[i];
				p1->fq[i]=0;
			}
		}
		if(lz==2)
		{
			swap(p1,p2);
		}
		p1->lz=lz;
		p2->lz=lz;
		lz=0;
	}
	void ud(long long lh,long long rh,long long ky)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			long long k=r-l+1,i,kk;
			
			if(ky==1)
			{
				for(i=0;i<p;i++)
				{
					fq[i]=0;
				}
				for(;1;p++)
				{
					kk=min(rs[p],k);
					fq[p]=kk;
					rs[p]-=kk;
					k-=kk;
					if(!k)
					{
						break;
					}
				}
				for(i=p+1;i<26;i++)
				{
					fq[i]=0;
				}
			}
			else if(ky==2)
			{
				for(i=25;i>p;i--)
				{
					fq[i]=0;
				}
				for(;1;p--)
				{
					kk=min(rs[p],k);
					fq[p]=kk;
					rs[p]-=kk;
					k-=kk;
					if(!k)
					{
						break;
					}
				}
				for(i=p-1;i>=0;i--)
				{
					fq[i]=0;
				}
			}
			lz=ky;
		}
		else
		{
			blc();
			p1->ud(lh,rh,ky);
			p2->ud(lh,rh,ky);
			fq=mrg(p1->fq,p2->fq);
		}
	}
	array<long long,26> sm(long long lh,long long rh)
	{
		array<long long,26> k={};
		if(l>rh||r<lh)
		{
			return k;
		}
		else if(l>=lh&&r<=rh)
		{
			return fq;
		}
		else
		{
			blc();
			return mrg(p1->sm(lh,rh),p2->sm(lh,rh));
		}
	}
	long long pt(long long lh)
	{
		if(l>lh||r<lh)
		{
			return 0;
		}
		else if(l==lh&&r==lh)
		{
			long long i;
			
			for(i=0;i<26;i++)
			{
				if(fq[i])
				{
					return i;
				}
			}
		}
		else
		{
			blc();
			return p1->pt(lh)+p2->pt(lh);
		}
	}
}
sg;

int main()
{
	long long i,t,rr,k,l,ky;
	string s;
	
	scanf("%lld%lld",&n,&t);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&ky);
		if(!ky)
		{
			ky=2;
		}
		rs=sg.sm(k,l);
		if(ky==1)
		{
			p=0;
		}
		else
		{
			p=25;
		}
		sg.ud(k,l,ky);
	}
	for(i=1;i<=n;i++)
	{
		printf("%c",(char)sg.pt(i)+'a');
	}
	printf("\n");
}