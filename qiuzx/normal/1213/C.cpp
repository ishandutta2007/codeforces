#include <bits/stdc++.h>
using namespace std;
long long q,n,m,sum[12];
vector<long long> num[12];
int main(){
	long long i,j,x;
	for(i=0;i<10;i++)
	{
		j=i;
		num[i].push_back(i);
		sum[i]=i;
		while(1)
		{
			j=(j+i)%10;
			if(j==num[i][0])
			{
				break;
			}
			sum[i]+=j;
			num[i].push_back(j);
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>n>>m;
		n/=m;
		m%=10;
		x=n/(num[m].size());
		j=n%(num[m].size());
		x*=sum[m];
		for(i=0;i<j;i++)
		{
			x+=num[m][i];
		}
		cout<<x<<endl;
	}
	return 0;
}