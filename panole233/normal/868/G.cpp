#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod=1000000007;
int n,k,p,T,ans,g;

int quickmi(int a,int b)
{
	int t=1;
	while (b)
	{
		if (b&1) t=1ll*t*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return t;
}

int gcd(int a,int b) {return (b)?gcd(b,a%b):a;}

pair<int,int> solve(int n,int k,int a_k,int a_b,int b_k,int b_b)
{
	if (a_k<0) a_k+=mod;
	if (n==1) return make_pair(1ll*a_b*quickmi(1-a_k,mod-2)%mod,0);
	pair<int,int> ans; int a=n/k;
	if (a_k==1) ans=solve(k,n%k,quickmi(b_k,mod-2),(1ll*(-a+1)*a_b-1ll*b_b*quickmi(b_k,mod-2))%mod,quickmi(b_k,mod-2),(-1ll*a*a_b-1ll*b_b*quickmi(b_k,mod-2))%mod);
	else 
	{
		int axk=quickmi(quickmi(a_k,a-1),mod-2),axb=1ll*(1-quickmi(a_k,a-1))*quickmi(a_k-1,mod-2)%mod*a_b%mod*axk%mod;
		int bxk=quickmi(quickmi(a_k,a),mod-2),bxb=1ll*(1-quickmi(a_k,a))*quickmi(a_k-1,mod-2)%mod*a_b%mod*bxk%mod;
		ans=solve(k,n%k,1ll*quickmi(b_k,mod-2)*axk%mod,(axb-1ll*quickmi(b_k,mod-2)*axk%mod*b_b)%mod,1ll*quickmi(b_k,mod-2)*bxk%mod,(bxb-1ll*quickmi(b_k,mod-2)*bxk%mod*b_b)%mod);
	}
	int an=1ll*quickmi(a_k,a)*ans.second%mod;
	if (a_k==1) an=(an+1ll*(n%k)*a_b%mod*a)%mod;
	else an=(an+1ll*(n%k)*a_b%mod*(quickmi(a_k,a)-1)%mod*quickmi(a_k-1,mod-2))%mod;
	if (a_k!=1)
	{
		int ik=quickmi(a_k-1,mod-2);
		an=(an+(1ll*(quickmi(a_k,a)-a_k)*ik-a+1)%mod*ik%mod*a_b%mod*k+1ll*(quickmi(a_k,a)-1)*ik%mod*ans.first)%mod;
	} else an=(an+1ll*ans.first*a+1ll*a*(a-1)/2%mod*a_b%mod*k)%mod; 
	return make_pair(an,ans.first);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k); p=quickmi(2,mod-2); g=gcd(n,k); n/=g; k/=g;
		if (n==1&&k==1) {printf("%d\n",quickmi(p,mod-2)); continue;}
		ans=1ll*quickmi(n,mod-2)*solve(n,k,1,1,1-p,1).first%mod;
		printf("%d\n",(ans+mod)%mod);
	}
	return 0;
}