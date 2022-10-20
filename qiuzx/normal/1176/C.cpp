#include <bits/stdc++.h>
#define N 500010
using namespace std;
int tn[50],n,a,i,ans=0,num[6]={};
int main(){
	cin>>n;
	tn[4]=0;
	tn[8]=1;
	tn[15]=2;
	tn[16]=3;
	tn[23]=4;
	tn[42]=5;
	for(i=0;i<n;i++)	
	{
		cin>>a;
		a=tn[a];
		if(a==0)
		{
			num[0]++;
		}
		else if(!num[a-1])
		{
			ans++;
		}
		else
		{
			num[a]++;
			num[a-1]--;
		}
	}
	for(i=0;i<5;i++)
	{
		ans+=num[i]*(i+1);
	}
	cout<<ans<<endl;
	return 0;
}