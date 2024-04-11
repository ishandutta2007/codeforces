#include <bits/stdc++.h>
using namespace std;
#define lll long long
vector<lll> fac;
lll sum[150][20000],k[2];
int main(){
  lll h, n, i, a, b,j,l,ll,maxx=-100000000000000001;
	cin>>n;
	for (i=1;i<=n;i++) if ((n%i==0)and(n/i>=3)) fac.push_back(i);
	for (i=0;i<n;i++)
	{
	cin>>a;
	for (j=0;j<fac.size();j++) sum[j][i%fac[j]]+=a;
	}
	for (j=0;j<fac.size();j++) for (i=0;i<fac[j];i++) if (sum[j][i]>maxx) maxx=sum[j][i];

    cout<<maxx;
}