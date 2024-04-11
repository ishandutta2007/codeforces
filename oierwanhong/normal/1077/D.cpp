#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;

ll n,k,ans=0,t;
ll out[1000001],cnt[1000001];
struct one
{
	ll v,use;
	bool operator <(const one &to)const
	{
		return ((double)cnt[v]/(use+1))<((double)cnt[to.v]/(to.use+1));
	}
};
priority_queue<one>q1,q2;
void fir()
{
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>t;
		cnt[t]++;
	}
	for(ll i=1;i<=200000;i++)
	{
		q1.push((one){i,0});
	}
}
void work()
{
	q2.push((one){q1.top().v,1});
	q1.pop();
	cout<<q2.top().v<<" ";
	for(ll i=2;i<=k;i++)
	{
		if(cnt[q1.top().v]>cnt[q2.top().v]/(q2.top().use+1))
		{
			q2.push((one){q1.top().v,1});
			cout<<q1.top().v<<" ";
			q1.pop();
		}
		else
		{
			q2.push((one){q2.top().v,q2.top().use+1});
			cout<<q2.top().v<<" ";
			q2.pop();
		}
	}
}
int main()
{
	
	fir();
	
	work();
	
	
	return 0;
}