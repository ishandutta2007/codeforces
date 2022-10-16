#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,a[500069],dg[500069],pst[500069],fw[26][500069],c=0,fwp;
vector<int> cd[500069];
pair<pair<int,int>,int> qq[500069];
queue<pair<int,int>> q;
bitset<500069> z;

void dfs(int x)
{
	int i,sz=cd[x].size(),l;
	
	c++;
	pst[x]=c;
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		dfs(l);
		dg[x]+=dg[l]+1;
	}
}

void ud(int x,int y,int w)
{
	for(fwp=y;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[x][fwp]+=w;
	}
}

int sm(int x,int lh,int rh)
{
	int z=0;
	
	for(fwp=rh;fwp>0;fwp-=fwp&-fwp)
	{
		z+=fw[x][fwp];
	}
	for(fwp=lh-1;fwp>0;fwp-=fwp&-fwp)
	{
		z-=fw[x][fwp];
	}
	return z;
}

int main()
{
	int t,i,j,k,l,pz,w,kk,sz,ll;
	string s;
	
	scanf("%d%d",&n,&t);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&k);
		cd[k].push_back(i);
	}
	dfs(1);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&qq[i].fr.sc,&qq[i].fr.fr);
		qq[i].sc=i;
	}
	sort(qq,qq+t);
	q.push({1,1});
	ud(a[1],pst[1],1);
	for(i=0;i<t;i++)
	{
		k=qq[i].fr.sc;
		l=qq[i].fr.fr;
		pz=qq[i].sc;
		for(;!q.empty();)
		{
			kk=q.front().fr;
			w=q.front().sc;
			if(w==l)
			{
				break;
			}
			q.pop();
			ud(a[kk],pst[kk],-1);
			sz=cd[kk].size();
			for(j=0;j<sz;j++)
			{
				ll=cd[kk][j];
				q.push({ll,w+1});
				ud(a[ll],pst[ll],1);
			}
		}
		c=0;
		for(j=0;j<26;j++)
		{
			if(sm(j,pst[k],pst[k]+dg[k])%2==1)
			{
				c++;
			}
		}
		if(c<=1)
		{
			z[pz]=1;
		}
	}
	for(i=0;i<t;i++)
	{
		if(z[i])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}