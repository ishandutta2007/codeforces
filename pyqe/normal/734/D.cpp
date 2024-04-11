#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ys,xs,yk[26];
pair<long long,long long> mne[8];

int main()
{
	long long i,k,y,x,im,ky[8]={-1,-1,-1,0,1,1,1,0},kx[8]={-1,0,1,1,1,0,-1,-1},ds,e;
	char ch;
	
	yk[17]=1;
	yk[16]=2;
	for(im=0;im<8;im++)
	{
		mne[im]={1e18,-1};
	}
	scanf("%lld%lld%lld",&n,&ys,&xs);
	for(i=1;i<=n;i++)
	{
		scanf(" %c%lld%lld",&ch,&y,&x);
		k=yk[ch-'A'];
		y-=ys;
		x-=xs;
		ds=max(abs(y),abs(x));
		for(im=0;im<8;im++)
		{
			if(y==ds*ky[im]&&x==ds*kx[im])
			{
				mne[im]=min(mne[im],{ds,k});
				break;
			}
		}
	}
	for(im=0;im<8;im++)
	{
		e=mne[im].sc;
		if(e==2||(e>=0&&e==im%2))
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}