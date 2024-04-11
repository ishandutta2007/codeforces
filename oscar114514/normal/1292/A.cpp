#include<bits/stdc++.h>
using namespace std;
int n,k,x,y;
int s[233333][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	int t=0;
	for(int i=1;i<=k;i++)
	{
		cin>>y>>x;
		if(s[x][y]==1)
		{
			s[x][y]=0;
			if(s[x-1][3-y]==1)t--;
			if(s[x][3-y]==1)t--;
			if(s[x+1][3-y]==1)t--;
		}
		else
		{
			s[x][y]=1;
			if(s[x-1][3-y]==1)t++;
			if(s[x][3-y]==1)t++;
			if(s[x+1][3-y]==1)t++;
		}
		if(t)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}