#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
mat mul(mat &a,mat &b)
{
	mat c(a.size(),vec(b[0].size()));
	for(int i=0;i<a.size();i++)
		for(int k=0;k<b.size();k++)
			for(int j=0;j<b[0].size();j++)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
	return c;
}
mat pow(mat a,ll n)
{
	mat b(a.size(),vec(a.size()));
	for(int i=0;i<a.size();i++)
		b[i][i]=1;
	while(n)
	{
		if(n&1)b=mul(b,a);
		a=mul(a,a);
		n>>=1;
	}
	return b;
}
int main()
{
	ll n;
	cin>>n;
	if(n==0)
	{
		cout<<1;
		return 0;
	}
	mat b(2,vec(2));
	b[0][0]=0;
	b[0][1]=1;
	b[1][0]=mod-8;
	b[1][1]=6;
	b=pow(b,n);
	cout<<(3*b[0][1]%mod+b[0][0]%mod)%mod;
	return 0;
}