#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
struct alpha{
	alpha* next[26];
};
alpha *getnode() {
	alpha *temp = new alpha;
	for (int i = 0; i < 26; ++i)
	{
		temp->next[i] = NULL;
	}
	return temp;
}
int main()
{
	int n;
	ll mod = 1000000007;
	cin>>n;
	std::vector<ll> p(n);
	std::vector<ll> time(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
		p[i]--;
	}
	std::vector<ll> presum(n, 0);
	time[0] = 2;
	presum[0] = 2;
	for (int i = 1; i < n; ++i)
	{
		if(p[i] == i)
		{
			time[i] = 2;
			presum[i] = (presum[i-1] + 2)%mod;
		}
		else {
			if(p[i] == 0)
				time[i] = (2 + presum[i-1])%mod;
			else
				time[i] = (2 + presum[i-1] - presum[p[i]-1])%mod;
			presum[i] = (presum[i-1] + time[i])%mod;
		}
	}
	cout<<(presum[n-1]+mod)%mod;
}