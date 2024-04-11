#include <bits/stdc++.h>

using namespace std;

long long n,m=0,nn[2],nm[2][2],sk[2][100069],yk[2][2][100069],zs=0;
bitset<100069> a;
vector<long long> vl[100069];

void prf(long long x)
{
	long long i,sz=vl[x].size();
	
	for(i=0;i<sz;i++)
	{
		zs++;
		printf("%lld%c",vl[x][i]," \n"[zs==n]);
	}
}

int main()
{
	long long i,ii,k,l,sz,sz2,e,e2;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]=='R';
		if(!nn[!a[i]])
		{
			nn[!a[i]]++;
			m++;
			sk[!a[i]][nn[!a[i]]]=m;
		}
		nn[a[i]]++;
		sk[a[i]][nn[a[i]]]=sk[!a[i]][nn[!a[i]]];
		nn[!a[i]]--;
		vl[sk[a[i]][nn[a[i]]]].push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		sz=vl[i].size();
		e=a[vl[i][0]];
		e2=a[vl[i][sz-1]];
		nm[e][e2]++;
		yk[e][e2][nm[e][e2]]=i;
		zs+=sz;
	}
	if(nm[0][1]&&nm[1][0]&&!nm[0][0]&&!nm[1][1])
	{
		k=yk[0][1][nm[0][1]];
		l=yk[1][0][nm[1][0]];
		sz=vl[k].size();
		sz2=vl[l].size();
		if(vl[k][sz-1]<vl[l][sz2-1])
		{
			swap(k,l);
		}
		sz=vl[k].size();
		vl[l].push_back(vl[k][sz-1]);
		vl[k].pop_back();
		for(ii=0;ii<2;ii++)
		{
			nm[ii][!ii]--;
			e=a[vl[k][0]];
			nm[e][e]++;
			yk[e][e][nm[e][e]]=k;
			swap(k,l);
		}
	}
	printf("%lld\n",m-1);
	e=nm[1][1]>nm[0][0];
	for(i=1;i<=nm[e][!e];i++)
	{
		prf(yk[e][!e][i]);
	}
	prf(yk[e][e][nm[e][e]]);
	nm[e][e]--;
	for(i=1;i<=nm[!e][e];i++)
	{
		prf(yk[!e][e][i]);
	}
	for(e^=1;nm[e][e];e^=1)
	{
		prf(yk[e][e][nm[e][e]]);
		nm[e][e]--;
	}
}