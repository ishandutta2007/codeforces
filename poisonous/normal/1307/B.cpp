#include<bits/stdc++.h>
using namespace std;
int num[100010];
int main()
{	
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>num[i];
		int x=0;
		for(int i=1;i<=n;i++)
		{
			if(num[i]==m)
			{
				cout<<1<<endl;
				x=1;
				break;
			}
		}
		if(x==1)
			continue;
		sort(num+1,num+n+1);
		cout<<max(2,(m/num[n]+((m%num[n])!=0)))<<endl;
	}
}