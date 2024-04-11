#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=26;
long long n,m,nn[2],pr[400069],dh[400069],ln[400069],ca[2][400069],fq[mm],kd[400069],sq[400069];
vector<long long> al[400069],a[400069],pst[400069];
bitset<400069> vtd;
vector<pair<pair<long long,long long>,long long>> ed[400069];
queue<long long> q;

inline void no()
{
	printf("NO\n");
	exit(0);
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			dh[l]=dh[x]+1;
			dfs(l);
		}
	}
	sq[x]=-1;
}

inline void chk2(long long x,bool w)
{
	if(kd[x]==-1)
	{
		q.push(x);
		kd[x]=w;
	}
	else if(kd[x]!=w)
	{
		no();
	}
}

inline void chk(long long x,long long w)
{
	if(sq[x]==-1)
	{
		long long i,k,l,sz=ed[x].size(),p;
		
		sq[x]=w;
		for(i=0;i<sz;i++)
		{
			k=ed[x][i].fr.fr;
			l=ed[x][i].fr.sc;
			p=ed[x][i].sc;
			if(k!=w&&l!=w)
			{
				no();
			}
			else if(k!=w||l!=w)
			{
				chk2(p,l==w);
			}
		}
	}
	else if(sq[x]!=w)
	{
		no();
	}
}

inline void bfs()
{
	long long i,k,l,p;
	
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		for(i=0;i<ln[k];i++)
		{
			l=a[k][i];
			p=pst[k][i];
			if(kd[k])
			{
				p=pst[k][ln[k]-1-i];
			}
			chk(p,l);
		}
	}
}

int main()
{
	long long i,j,ii,u,k,l,sz,e,p,c;
	pair<long long,long long> mxe;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		cin>>s;
		ln[i]=s.length();
		for(j=0;j<ln[i];j++)
		{
			a[i].push_back(s[j]-'a');
		}
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		e=0;
		for(;1;k=pr[k])
		{
			if(dh[l]>dh[k])
			{
				swap(k,l);
				e^=1;
			}
			nn[e]++;
			ca[e][nn[e]]=k;
			if(k==l)
			{
				break;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(j=1+(nn[ii]-1)*ii;j&&j<=nn[ii];j+=u)
			{
				pst[i].push_back(ca[ii][j]);
			}
		}
		for(j=0;j<ln[i];j++)
		{
			k=a[i][j];
			l=a[i][ln[i]-1-j];
			p=pst[i][j];
			ed[p].push_back({{k,l},i});
		}
		kd[i]=-1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<mm;j++)
		{
			fq[j]=0;
		}
		c=0;
		sz=ed[i].size();
		for(j=0;j<sz;j++)
		{
			k=ed[i][j].fr.fr;
			l=ed[i][j].fr.sc;
			p=ed[i][j].sc;
			if(k==l)
			{
				break;
			}
			for(ii=0;ii<2;ii++)
			{
				c+=!fq[k];
				fq[k]++;
				swap(k,l);
			}
		}
		if(j<sz)
		{
			chk(i,k);
		}
		else if(c>2)
		{
			mxe.fr=0;
			for(j=0;j<mm;j++)
			{
				mxe=max(mxe,{fq[j],j});
			}
			e=mxe.sc;
			chk(i,e);
		}
	}
	bfs();
	for(i=1;i<=m;i++)
	{
		if(kd[i]==-1)
		{
			chk2(i,0);
			bfs();
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		sq[i]=max(sq[i],0ll);
		printf("%c",(char)(sq[i]+'a'));
	}
	printf("\n");
}