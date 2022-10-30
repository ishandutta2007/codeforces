#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b-1;i>=a;i--)
#define ll long long
#define mod (ll)1000000007
using namespace std;
struct mat{
	ll a[5][5];
};
mat A,E,zero,F;
ll quick(ll a,ll b,ll c){
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res; 
}
mat mul(mat a,mat b,ll c){
	mat res=zero;
	rep(k,0,5)rep(i,0,5){
		if(!a.a[i][k])continue;
		rep(j,0,5)if(b.a[k][j])res.a[i][j]=(res.a[i][j]+a.a[i][k]*b.a[k][j])%c;
	}
	return res;
}
mat quick_mat(mat a,ll b,ll c){
	mat res=E;
	while(b){
		if(b&1)res=mul(res,a,c);
		a=mul(a,a,c);
		b>>=1;
	}
	return res;
}
int main()
{
	ll n,c;
	rep(i,0,5)E.a[i][i]=1;
	cin>>n>>F.a[0][3]>>F.a[0][2]>>F.a[0][1]>>c;
	F.a[0][0]=F.a[0][4]=(c*c)%mod;
	rep(i,1,4)F.a[0][i]%mod;
/*	if(n<=3){
		cout<<F.a[0][4-n];
		return 0;
	}*/
	A.a[0][0]=A.a[4][0]=A.a[0][1]=A.a[1][1]=A.a[2][1]=A.a[3][1]=A.a[1][2]=A.a[2][3]=A.a[4][4]=1;
	A=quick_mat(A,n-3,mod-1);
	ll ans=1;
	rep(i,0,5){
		ans=(ans*quick(F.a[0][i],A.a[i][1],mod))%mod;
	//	cout<<A.a[i][1]<<' '<<ans<<"A\n";
	}
	cout<<ans;
}