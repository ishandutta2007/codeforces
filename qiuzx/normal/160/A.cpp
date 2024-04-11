#include <bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int> pq;
	int a,n,i,sum=0,num=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		sum+=a;
		pq.push(a);
	}
	for(i=0;i<n;i++)
	{
		num+=pq.top();
		pq.pop();
		if(num>sum/2)
			break;
	}
	cout<<i+1<<endl;
	return 0;
}