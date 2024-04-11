#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

priority_queue<long long>q;

long long a[N],n;

long long ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],q.push(-a[i]);
	if(n%2==0)
	{
		long long a=q.top();
		q.pop();
		long long b=q.top();
		q.pop();
		q.push(a+b);
		ans+=a+b;
		n--;
	}
	while(n>1)
	{
		long long a=q.top();
		q.pop();
		long long b=q.top();
		q.pop();
		long long c=q.top();
		q.pop();
		q.push(a+b+c);
		ans+=a+b+c;
		n-=2;
	}
	cout<<-ans;
}