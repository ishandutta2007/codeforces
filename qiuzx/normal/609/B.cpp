#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,a,ans=0,gen[15],i,j;
	cin>>n>>m;
	memset(gen,0,sizeof(gen));
	for(i=0;i<n;i++)
	{
		cin>>a;
		gen[a-1]++;
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			ans+=gen[i]*gen[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}