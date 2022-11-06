#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		long long l,r;
		cin>>l>>r;
		auto solve=[&](long long x)
		{
			long long s=sqrtl((long double)x);
			while((s+1)*(s+1)<=x)s++;
			while(s>0 and (s-1)*(s-1)>x)s--;
			long long ans=3*s;
			if(x>=s*(s+1))ans++;
			if(x>=s*(s+2))ans++;
			return ans;
		};
		cout<<solve(r)-solve(l-1)<<endl;
	}
	return 0;
}