#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,minx=120,maxx=0,miny=120,maxy=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		char t;
		cin>>t;
		if(t=='B')
		{
		minx=min(minx,i);
		miny=min(miny,j);
		maxx=max(maxx,i);
		maxy=max(maxy,j);
		}
	}
	printf("%d %d",(maxx+minx)/2,(miny+maxy)/2);
}