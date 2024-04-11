#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n,a,b,vis[9][9],ca[9][9],cb[9][9],ansa[11],ansb[11];

ll fa,fb;

ll win[4][4];

int main()
{
	cin>>n>>a>>b;
	vis[a][b]=1;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			cin>>ca[i][j];
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			cin>>cb[i][j];
	win[3][2]=1,win[2][3]=-1;
	win[2][1]=1,win[1][2]=-1;
	win[1][3]=1,win[3][1]=-1;
	int nowa,nowb;
	nowa=a,nowb=b;
	if(win[a][b]==1)
		ansa[1]++;
	if(win[a][b]==-1)
		ansb[1]++;
	for(int i=2;i<=n;i++)
	{
		int tmpa=ca[nowa][nowb];
		int tmpb=cb[nowa][nowb];
		nowa=tmpa,nowb=tmpb;
		ansa[i]+=ansa[i-1]+(win[nowa][nowb]==1);
		ansb[i]+=ansb[i-1]+(win[nowa][nowb]==-1);
		if(vis[nowa][nowb])
		{
			int tmp=i-vis[nowa][nowb];
			int dta=ansa[i]-ansa[vis[nowa][nowb]];
			int dtb=ansb[i]-ansb[vis[nowa][nowb]];
			fa+=(n-i)/tmp*dta+ansa[i];
			fb+=(n-i)/tmp*dtb+ansb[i];
			if((n-i)%tmp!=0)	
				fa+=ansa[vis[nowa][nowb]+(n-i)%tmp]-ansa[vis[nowa][nowb]],
				fb+=ansb[vis[nowa][nowb]+(n-i)%tmp]-ansb[vis[nowa][nowb]];
			cout<<fa<<" "<<fb;
			return 0;
		}
		vis[nowa][nowb]=i;
	}
	cout<<ansa[n]<<" "<<ansb[n];
}