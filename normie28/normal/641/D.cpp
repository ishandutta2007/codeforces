#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ld arr[100001],brr[100001];
ld prea[100001],preb[100001];
ld resa[100001],resb[100001];
ld ra,rb,rc,rd,re,rf,rg,rh;
ll n,m,i,j,k,t,t1,u,v,a,b; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		arr[i]=abs(arr[i]);
		prea[i]=prea[i-1]+arr[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>brr[i];
		arr[i]=abs(brr[i]);
		preb[i]=preb[i-1]+brr[i];
	}
	for (i=1;i<=n;i++)
	{
		ra=prea[i];
		rb=preb[n]-preb[i];
		rb=-(rb-ra-1);
		rc=rb*rb-4*ra;
		rc=abs(rc);
		assert(rc>=0 && "Wait why the fuck is this part negative");
		rc=sqrt(rc);
	//	cout<<i<<' '<<rb<<' '<<rc<<endl;
		resa[i]=(rc+rb)/2;
		resb[i]=(rb-rc)/2;
	}
	for (i=1;i<=n;i++)
	{
		cout<<fixed<<setprecision(9)<<resa[i]-resa[i-1]<<' ';

	}
	cout<<endl;
	for (i=1;i<=n;i++)
	{
		cout<<fixed<<setprecision(9)<<resb[i]-resb[i-1]<<' ';

	}
}