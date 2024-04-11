#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
const int MOD = 998244353;
typedef long long ll;
ll mul(ll x , ll y) {return x * y % MOD;}
ll add(ll x , ll y) {return (x + y >= MOD ? x + y - MOD : x + y);}
ll sub(ll x , ll y) {return (x < y ? x + MOD - y : x - y);}

int n , K , m;
int l[N] , r[N] , x[N];

int a[N] , b[N];
ll f[N];

ll ans = 1;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> K >> m;
	for(int i = 1; i <= m; i++)
		cin >> l[i] >> r[i] >> x[i];
	for(int k = 0; k < K; k++)
	{
		memset(a , 0 , sizeof a);memset(b , 0 , sizeof b);
		memset(f , 0 , sizeof f);
		for(int i = 1; i <= m; i++)
		{
			if((1 << k) & x[i])
				a[l[i]]++ , a[r[i] + 1]--;
			else
				b[r[i] + 1] = max(b[r[i] + 1] , l[i]);
		}
		for(int i = 2; i <= n + 1; i++)
			a[i] += a[i - 1] , b[i] = max(b[i] , b[i - 1]);
		f[0] = 1;
		ll sum = 1 , l = 0;
		for(int i = 1; i <= n + 1; i++)
		{
			while(l < b[i])
				sum = sub(sum , f[l]) , l++;
			f[i] = (a[i] ? 0 : sum) , sum = add(sum , f[i]);
		}
		ans = mul(ans , f[n + 1]);
	}
	cout << ans << endl;
	return 0;
}