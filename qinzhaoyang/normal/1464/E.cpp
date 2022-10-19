#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 998244353 , N = 1 << 22;

ll add(ll x , ll y) {return (x + y) % MOD;}
ll sub(ll x , ll y) {return ((x - y) % MOD + MOD) % MOD;}
ll mul(ll x , ll y) {return x * y % MOD;}
ll change(ll x) {return (x % MOD + MOD) + MOD;}

void exgcd(ll a , ll b , ll &x , ll &y)
{
	if(b == 0)
	{
		x = 1 , y = 0;
		return;
	}
	exgcd(b , a % b , y , x);
	y -= (a / b) * x;
}

ll get(ll a)
{
	ll x , y; exgcd(a , MOD , x , y);
	return change(x);
}

int n , m , limit = 1;
vector <int> v[N];
ll sg[N] , cnt[N];

void dfs(int x)
{
	if(sg[x] != -1)
		return;
	vector <int> nxt;
	for(int i = 0; i < v[x].size(); i++)
		dfs(v[x][i]) , nxt.push_back(sg[v[x][i]]);
	sort(nxt.begin() , nxt.end());
	ll mex = 0;
	for(int i = 0; i < nxt.size(); i++)
		if(nxt[i] == mex)
			mex++;
	sg[x] = mex;
}

ll a[N] , b[N];

void FWT(ll *a , ll type)
{
	for(int i = 1; i < limit; i <<= 1)
		for(int j = 0; j < limit; j += (i << 1))
			for(int k = 0; k < i; k++)
			{
				ll tx = mul(a[j + k] , type) , ty = mul(a[i + j + k] , type);
				a[j + k] = add(tx , ty) , a[i + j + k] = sub(tx , ty);
			}
}

int main()
{
	ios::sync_with_stdio(false);
	memset(sg , -1 , sizeof sg);
	cin >> n >> m;
	while(limit <= n)
		limit <<= 1;
	for(int i = 1 , from , to; i <= m; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
	}
	for(int i = 1; i <= n; i++)
		dfs(i);
	for(int i = 1; i <= n; i++)
		cnt[sg[i]]++;
	ll invn_1 = get(n + 1);
	for(int i = 0; i < limit; i++)
		b[i] = mul(cnt[i] , invn_1);
	b[0] = sub(b[0] , 1) , a[0] = sub(0 , invn_1);
	FWT(a , 1) , FWT(b , 1);
	for(int i = 0; i < limit; i++)
		a[i] = mul(a[i] , get(b[i]));
	FWT(a , get(2));
	cout << sub(1 , a[0]) << endl;
	return 0;
}