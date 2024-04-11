#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<ll>q;
ll n,x,ans;
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		if (q.size()&&-q.top()<x)
		{
			ans+=x+q.top();
			q.pop();
			q.push(-x);
		}
		q.push(-x);
	}
	cout << ans << endl;
    return 0;
}