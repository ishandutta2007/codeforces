#include<bits/stdc++.h>
#define sz 100010
using namespace std;
typedef long long ll;
ll n,m;
ll a[sz],b[sz];
ll cut[sz];
ll cur,tot,tt;
bool cmp(const ll &a,const ll &b){return a>b;}
int main()
{
	scanf("%I64d %I64d",&n,&m);
	int i;
	for (i=1;i<=n;i++) 
		scanf("%I64d %I64d",&a[i],&b[i]),
		cut[i]=a[i]-b[i],
		tot+=a[i],
		tt+=b[i];
	if (tt>m) return 0&puts("-1");
//	if (tot<=m) return 0&puts("0");
	sort(cut+1,cut+n+1,cmp);
	i=0;
	while (tot>m) tot-=cut[++i];
	cout<<i;
}