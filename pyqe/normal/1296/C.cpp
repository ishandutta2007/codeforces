#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,yk[26];
map<pair<long long,long long>,long long> ls;

int main()
{
	long long t,rr,i,k,x,y,kx[4]={0,1,0,-1},ky[4]={1,0,-1,0},mn,e;
	string s;
	pair<long long,long long> mne;
	
	yk[20]=0;
	yk[17]=1;
	yk[3]=2;
	yk[11]=3;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		ls.clear();
		mne={1e18,-1};
		x=0;
		y=0;
		ls[{x,y}]=1;
		for(i=1;i<=n;i++)
		{
			k=yk[s[i-1]-'A'];
			x+=kx[k];
			y+=ky[k];
			if(ls[{x,y}])
			{
				mne=min(mne,{i+1-ls[{x,y}],i});
			}
			ls[{x,y}]=i+1;
		}
		mn=mne.fr;
		e=mne.sc;
		if(e==-1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld %lld\n",e-mn+1,e);
		}
	}
}