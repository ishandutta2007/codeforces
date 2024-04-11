// Author: Little09
// Problem: CF1485F Copy or Prefix Sum
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1485F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
const ll mod=1000000007;

const int N=500005;
int n,m; 
ll b[N],res;
map<ll,ll>q;

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> b[i];
	q.clear();
	q[0]=1,res=1;
	ll sum=0;
	for (int i=1;i<=n;i++)
	{
		ll tmp=(res-q[-sum]+mod)%mod;
		sum+=b[i];
		q[b[i]-sum]=(q[b[i]-sum]+tmp)%mod;
		res=(res+tmp)%mod;
	}
	cout << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}