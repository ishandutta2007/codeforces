#include <bits/stdc++.h>
using namespace std;
#define ll int
#define MODD 100000000003
struct tup {vector <ll> a;};
vector <ll> all; tup h;
ll a, b, n, m, i, j,ii,jj, k, t, mon[1000001], d=0, bar=10000000001;
char c1,c2;
typedef vector<int> vi;
vi line,s[5001];
void solve (ll l, ll r, ll i)
{
int mid=(l+r)/2;
cout<<mid<<endl;
	cin>>b;
	if (b==-2) exit(0);
	if (b==0) exit(0);
	b*=mon[i];
	if (b==1) solve(mid+1,r,(i%n)+1);
	else solve(l,mid-1,(i%n)+1);
}
int main()
{
	cin>>m>>n;
	for (i=1;i<=n;i++)
	{
	cout<<1<<endl;
	cin>>b;
	if (b==-2) return 0;
	if (b==0) return 0;
	else mon[i]=b;
	}
	solve(1,m,1);
}