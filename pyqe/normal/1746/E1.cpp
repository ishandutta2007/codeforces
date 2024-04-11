#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=17;
long long n,d;
bitset<mm> spc,vtd,sq;
vector<pair<long long,long long>> al[mm];

long long qr(long long x)
{
	long long i,sz;
	vector<long long> v;
	char ch;
	
	for(i=1;i<=n;i++)
	{
		if(i>>x&1)
		{
			v.push_back(i);
		}
	}
	sz=v.size();
	printf("? %lld",sz);
	for(i=0;i<sz;i++)
	{
		printf(" %lld",v[i]);
	}
	printf("\n");
	fflush(stdout);
	scanf(" %c",&ch);
	if(ch=='Y')
	{
		scanf(" %c %c",&ch,&ch);
		return 1;
	}
	else
	{
		scanf(" %c",&ch);
		return 0;
	}
}

void trv(long long x,bool kd)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	spc[x]=kd;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			sq[l]=sq[x]^w;
			trv(l,kd);
		}
	}
}

int main()
{
	long long i,ii,k,l,ca[4],z;
	char ch;
	
	scanf("%lld",&n);
	for(d=0;1ll<<d<=n;d++);
	l=0;
	for(i=1;i<d;i++)
	{
		ca[0]=qr(l);
		ca[1]=qr(i);
		ca[2]=qr(i);
		ca[3]=qr(l);
		if(ca[1]==ca[2])
		{
			sq[i]=ca[1];
			trv(i,1);
		}
		else if(ca[0]==ca[3])
		{
			sq[l]=ca[0];
			trv(l,1);
			l=i;
		}
		else
		{
			al[i].push_back({l,ca[0]^ca[2]});
			al[l].push_back({i,ca[0]^ca[2]});
		}
	}
	trv(l,0);
	for(ii=0;ii<2;ii++)
	{
		z=0;
		for(i=0;i<d;i++)
		{
			if(spc[i])
			{
				k=sq[i];
			}
			else
			{
				k=sq[i]^ii;
			}
			z|=k<<i;
		}
		if(z<1||z>n)
		{
			continue;
		}
		printf("! %lld\n",z);
		fflush(stdout);
		scanf(" %c %c",&ch,&ch);
		if(ch==')')
		{
			break;
		}
	}
}