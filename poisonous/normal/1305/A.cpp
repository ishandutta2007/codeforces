#include<bits/stdc++.h>
using namespace std;
int num[100010];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>num[i];
		sort(num+1,num+n+1);
		for(int i=1;i<=n;i++)
			cout<<num[i]<<' ';
		cout<<endl;
		for(int i=1;i<=n;i++)
			cin>>num[i];
		sort(num+1,num+n+1);
		for(int i=1;i<=n;i++)
			cout<<num[i]<<' ';
		cout<<endl;
	}		
}