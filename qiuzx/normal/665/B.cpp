#include <bits/stdc++.h>
#define N 105
using namespace std;
int main(){
	int n,k,m,pos[N],p,i,j,l,tm=0,a;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++)
	{
		cin>>p;
		pos[p]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a;
			tm+=pos[a];
			for(l=1;l<=k;l++)
			{
				if(pos[l]<pos[a])
				{
					pos[l]++;
				}
			}
			pos[a]=1;
		}
	}
	cout<<tm<<endl;
	return 0;
}