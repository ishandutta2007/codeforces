#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e6+5;
const int MOD=1e9+7;
 
int n, a[N], cnt[N], ans=0;
 
int32_t main()
{
	IOS;
	cin>>n;
	cnt[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vector<int> cur;
		for(int j=1;j*j<=a[i];j++)
		{		
			if(a[i]%j==0)
			{
				cur.push_back(j);
				if(j != a[i]/j)
					cur.push_back(a[i]/j);
			}
		}
		sort(cur.begin(), cur.end());
		reverse(cur.begin(), cur.end());
		for(auto &it:cur)
		{
			cnt[it]+=cnt[it-1];
			cnt[it]%=MOD;
		}
	}	
	for(int i=1;i<=n;i++)
		ans+=cnt[i];
	ans %= MOD;
	cout<<ans;
	return 0;
}