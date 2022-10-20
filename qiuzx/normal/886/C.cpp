#include <bits/stdc++.h>
#define N 200010 
using namespace std;
int n,t[N],i,been[N]={},ans=1;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	memset(been,-1,sizeof(been));
	been[0]=1;
	for(i=1;i<=n;i++)
	{
		if(been[t[i]]!=-1)
		{
			been[i]=been[t[i]];
			been[t[i]]=-1;
			continue;
		}
		ans++;
		been[i]=ans;
	}
	cout<<ans<<endl;
	return 0;
}