#include<bits/stdc++.h>
using namespace std;
int num[1010];
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
		for(int j=2;j<=n;j++)
		{
			while(num[j]>0&&m-(j-1)>=0)
			{
				num[1]++;
				num[j]--;
				m-=j-1;
			}
		}
		cout<<num[1]<<endl;
	}
}