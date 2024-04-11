#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 10000000000
#define N 100010
using namespace std;
ll n,cur[N],ans=0;
bool bd=false;
stack<ll> q;
string s;
int main(){
	ll i,x;
	cin>>n;
	cur[0]=1;
	for(i=1;i<=n;i++)
	{
		cur[i]=cur[i-1];
		cin>>s;
		if(s=="for")
		{
			cin>>x;
			cur[i]*=x;
			cur[i]=min(cur[i],INF);
			q.push(i);
		}
		else if(s=="add")
		{
			ans+=cur[i];
			if(ans>((ll)1<<(ll)32)-1)
			{
				puts("OVERFLOW!!!");
				return 0;
			}
		}
		else
		{
			cur[i]=cur[q.top()-1];
			q.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}