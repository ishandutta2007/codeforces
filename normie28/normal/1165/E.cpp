#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MODD 100000000003
struct tup {vector <ll> a;};
vector <ll> all; tup h;
ll a, b, n, m, i, j,ii,jj, k, t, mon[1000001], d=0;
char c1,c2;
typedef vector<ll> vi;
vi u,v;
int cmp(ll x, ll y)
{
	return(x>y);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
	cin>>a; u.push_back((a*(i)*(n-i+1)));
	}
	for (i=1;i<=n;i++)
	{
	cin>>a; v.push_back(a);
	}
	sort (u.begin(),u.end());
	sort (v.begin(),v.end(),cmp);
	for (i=1;i<=n;i++) {d+=(u[i-1]%998244353)*v[i-1]; d%=998244353;}
	cout<<d;
}