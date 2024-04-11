#include <bits/stdc++.h>
using namespace std;
#define ll int
#define MODD 100000000003
struct tup {vector <ll> a;};
vector <ll> all; tup h;
ll a=0, b=0, n, m, i, j,x,y, k, t, mon[1000001], d=0, bar=10000000001;
char c1,c2;
typedef vector<int> vi;
vi pset(1000), setSize(1000); 

int ask(ll x, ll y)
{
cout<<"? "<<x<<' '<<y<<endl;
int res;
cin>>res;
if (res==-2) exit(0);
return res;
}

int main()
{
	ll poww[1001];
	poww[0]=1;
	mon[30]=1;
	for (i=29;i>=0;i--)
	{
	if (mon[i+1]) {k=ask(a,b); if (k==0) break;}
	if (ask(a^(1<<i),b^(1<<i))!=k) 
	{
	mon[i]=1;
	if (k==1) a^=(1<<i); else b^=(1<<i);
	}
	}
	for (i=29;i>=0;i--) if (!mon[i])
	{
	if (ask(a,b^(1<<i))==1)  {a^=(1<<i); b^=(1<<i);}
	}
	cout<<"! "<<a<<' '<<b;
}