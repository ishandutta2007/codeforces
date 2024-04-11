#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long vx[8]={-1,1,0,0,-1,-1,1,1},vy[8]={0,0,1,-1,1,-1,1,-1},inf=1e18;
const string ky[8]={"L","R","U","D","LU","LD","RU","RD"};

int main()
{
	long long im,x,y,x2,y2,xx,yy,e;
	pair<long long,long long> mne;
	char ch;
	
	scanf(" %c",&ch);
	x=ch-'a';
	scanf(" %c",&ch);
	y=ch-'1';
	scanf(" %c",&ch);
	x2=ch-'a';
	scanf(" %c",&ch);
	y2=ch-'1';
	printf("%lld\n",max(abs(x-x2),abs(y-y2)));
	for(;x!=x2||y!=y2;x+=vx[e],y+=vy[e])
	{
		mne={inf,-1};
		for(im=0;im<8;im++)
		{
			xx=x+vx[im];
			yy=y+vy[im];
			mne=min(mne,{max(abs(xx-x2),abs(yy-y2)),im});
		}
		e=mne.sc;
		printf("%s\n",ky[e].c_str());
	}
}