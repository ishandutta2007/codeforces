#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,t,dp,un,x,y,a,b;
	cin>>un>>dp>>m>>t;
	while(t--)
	{
		cin>>x>>y;
		if(x==1)
		{
			un++;
			if(y<=dp)
			{
				dp++;
			}
		}
		else
		{
			a=y;
			b=un-y;
			if(y<dp)
			{
				dp-=a;
				un-=a;
			}
			else
			{
				un-=b;
			}
		}
		cout<<un<<" "<<dp<<endl;
	}
	return 0;
}