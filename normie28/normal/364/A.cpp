#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MODD 100000000003
struct tup {vector <ll> a;};
vector <ll> all; tup h;
ll a, b, n, m, i, j,ii,jj, k, t, pre[1000001];
char c,c2;
typedef vector<ll> vi;
vi lis;
int main()
{
	cin>>a;
	i=0;
	while (cin>>c) {i++; pre[i]=pre[i-1]+c-48; for (j=0;j<i;j++) {lis.push_back(pre[i]-pre[j]); }}
	sort (lis.begin(),lis.end());
	k=0;
	for (i=0;i<lis.size();i++) if ((a==0)and(lis[i]==0)) k+=lis.size(); else if (lis[i]>0) 
	if (a%lis[i]==0) k+=upper_bound(lis.begin(),lis.end(),a/lis[i])-lower_bound(lis.begin(),lis.end(),a/lis[i]);
	cout<<k;
}