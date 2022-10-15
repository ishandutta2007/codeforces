#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MODD 100000000003
struct tup {vector <ll> a;};
vector <ll> all; tup h;
ll a, b, n, m, i, j,ii,jj, k, t, mon[1000001], d=0;
char c1,c2;
typedef vector<int> vi;
string og,cur;
void solve(ll l, ll r, ll x)
{
ll mid=(l+r)/2;
if (x==n)
{
if (mid<=1000000000) cout<<mid<<' '<<0<<' '<<0<<' '<<mid<<endl;
else cout<<mid-1000000000<<' '<<1000000000<<' '<<1000000000<<' '<<mid-1000000000<<endl;
exit(0);
}
else
{
if (mid<=1000000000) cout<<mid<<' '<<0<<endl;
else cout<<mid-1000000000<<' '<<1000000000<<endl;
cin>>cur;
if (cur==og) solve(mid+1,r,x+1);
	else solve(l,mid-1,x+1);
}
}
int main()
{
	ll poww[1001];
	poww[0]=1;
	cin>>n;
	cout<<0<<' '<<0<<endl;
	cin>>og;
	solve(1,2000000000,1);
}