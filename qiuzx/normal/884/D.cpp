#include <bits/stdc++.h>
#define N 2010
using namespace std;
priority_queue<long long> pq;
long long n,ans=0;
int main(){
	long long x,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		pq.push(-x);
	}
	if(n%2==0)
	{
		pq.push(0);
	}
	while(pq.size()>1)
	{
		x=0;
		for(i=0;i<3;i++)
		{
			x+=-pq.top();
			pq.pop();
		}
		ans+=x;
		pq.push(-x);
	}
	cout<<ans<<endl;
	return 0;
}