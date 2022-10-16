#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,yk[26];
string ky="NESW";
map<pair<pair<long long,long long>,pair<long long,long long>>,bool> vtd;

int main()
{
	long long t,rr,i,k,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},z;
	string s;
	pair<long long,long long> cr,ls,tmp,tmp2;
	
	for(i=0;i<4;i++)
	{
		yk[ky[i]-'A']=i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		vtd.clear();
		cr={0,0};
		z=0;
		for(i=1;i<=n;i++)
		{
			k=yk[s[i-1]-'A'];
			ls=cr;
			cr.fr+=vy[k];
			cr.sc+=vx[k];
			tmp=ls;
			tmp2=cr;
			if(tmp>tmp2)
			{
				swap(tmp,tmp2);
			}
			z+=1+4*!vtd[{tmp,tmp2}];
			vtd[{tmp,tmp2}]=1;
		}
		printf("%lld\n",z);
	}
}