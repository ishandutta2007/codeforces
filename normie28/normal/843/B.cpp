#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MODD 100000000003
struct tup {vector <ll> a;};
vector <ll> all; tup h;
ll a, b, n, m, i, j,ii,jj, k, t, mon[1000001], d=0;
char c1,c2;
typedef vector<ll> vi;
vi lis;
ll ask(ll x)
{
ll ii,jj;
cout<<"? "<<x<<endl;
cin>>ii>>jj;
if (ii==-1) exit(0);
mon[x]=ii;
lis.push_back(x);
return jj;
}
int cmp (ll a, ll b) {return (mon[a]<mon[b]);}
int main()
{
	 srand(time(0));
	cin>>n>>a>>b;
	mon[0]=b;
	ask(a);
	for (i=1;i<=999;i++) ask(abs((rand()*rand()))%n+1);
	sort (lis.begin(),lis.end(),cmp);
	if (mon[lis[0]]>=b) cout<<"! "<<mon[lis[0]]; else
	{
	ii=*(lower_bound(lis.begin(),lis.end(),0,cmp)-1);
	jj=ask(ii);
	if (jj==-1) {cout<<"! "<<-1; return 0;}
	for (i=1;i<=990;i++) {
	k=ask(jj);
	if ((mon[ii]<b)and(mon[jj]>=b)) {cout<<"! "<<mon[jj]; return 0;}
	if (k==-1) {cout<<"! "<<-1; return 0;}
	ii=jj;
	jj=k;
	}
	cout<<"! "<<-1;
	}
}