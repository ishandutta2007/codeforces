#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],qq[100069],wg[10],ml[10],dv=1e9+7;
vector<long long> ql[100069];

int main()
{
	long long t,rr,i,k,ln,sz,w,ww,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		cin>>s;
		ln=s.length();
		qq[rr]=s[0]-'0';
		for(i=4;i<=ln;i++)
		{
			ql[rr].push_back(s[i-1]-'0');
		}
	}
	for(i=0;i<10;i++)
	{
		wg[i]=i;
		ml[i]=10;
	}
	for(rr=t;rr;rr--)
	{
		sz=ql[rr].size();
		w=0;
		ww=1;
		for(i=0;i<sz;i++)
		{
			k=ql[rr][i];
			w=(w*ml[k]+wg[k])%dv;
			ww=ww*ml[k]%dv;
		}
		wg[qq[rr]]=w;
		ml[qq[rr]]=ww;
	}
	for(i=1;i<=n;i++)
	{
		z=(z*ml[a[i]]+wg[a[i]])%dv;
	}
	printf("%lld\n",z);
}