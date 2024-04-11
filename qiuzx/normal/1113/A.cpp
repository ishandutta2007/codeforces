#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,v,i,fc,sum=0;
	cin>>n>>v;
	fc=n-v;
	if(fc<=1)
	{
		cout<<n-1<<endl;
		return 0;
	}
	for(i=1;i<=fc;i++)
	{
		sum+=i;
	}
	sum+=v-1;
	cout<<sum<<endl;
	return 0;
}