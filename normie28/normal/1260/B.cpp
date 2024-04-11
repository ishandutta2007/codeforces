#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MODD 100000000003
struct tup {vector <ll> a;};
vector <ll> all; tup h;
ll a, b, n, m, i, j,ii,jj, k, t, mon[1000001], d=0;
char c1,c2;
typedef vector<int> vi;
vi lis,num;
string og,cur;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
	cin>>a>>b;
	k=((a<b)?a:b)-abs(a-b);
	if ((k%3)or(k<0)) cout<<"NO"; else cout<<"YES";
	cout<<endl;
	}
}