#include <bits/stdc++.h>

using namespace std;

long long n,ln,a[200069],fq[4],zs;
vector<bool> v,vv;
map<vector<bool>,long long> ls;
bitset<200069> vtd;
vector<long long> sq;

int main()
{
	long long t,rr,i,j,k;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<4;i++)
		{
			fq[i]=0;
		}
		ls.clear();
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
			cin>>s;
			ln=s.length();
			v.clear();
			for(j=0;j<ln;j++)
			{
				v.push_back(s[j]-'0');
			}
			a[i]=v[0]+v[ln-1]*2;
			fq[a[i]]++;
			k=ls[v];
			if(k)
			{
				vtd[k]=1;
				vtd[i]=1;
			}
			else
			{
				vv.clear();
				for(j=0;j<ln;j++)
				{
					vv.push_back(v[ln-1-j]);
				}
				ls[vv]=i;
			}
		}
		if(fq[0]&&fq[3]&&!fq[1]&&!fq[2])
		{
			printf("-1\n");
			continue;
		}
		sq.clear();
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				if(a[i]&&a[i]<3&&fq[a[i]]>fq[3-a[i]]+1)
				{
					sq.push_back(i);
					zs++;
					fq[a[i]]--;
					fq[3-a[i]]++;
				}
			}
		}
		printf("%lld\n",zs);
		for(i=0;i<zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs-1]);
		}
	}
}