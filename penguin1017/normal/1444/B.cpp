#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second 
#define mp make_pair
#define all(x) x.begin(),x.end()
#define lb(x) ((x)&(-x))
#define ll long long 
#define vi vector<int>
using namespace std;
const int N=2e6+9;
const int mod=998244353;
int jie[N],inv[N];
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
} 
inline int mul(const int &a,const int &b){
	return 1ll*a*b%mod;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int C(const int &m,const int &n){
	if(n>m||m<0||n<0)return 0;
	return 1ll*jie[m]*inv[n]%mod*inv[m-n]%mod;
}
int a[N];
int main(){
	int n;
	scanf("%d",&n); 
	jie[0]=1,inv[0]=inv[1]=1;
	rep(i,2,N){
		inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	}
	rep(i,1,N){
		jie[i]=1ll*jie[i-1]*i%mod;
		inv[i]=1ll*inv[i]*inv[i-1]%mod;
	}
	rep(i,1,2*n+1)scanf("%d",&a[i]);
	sort(a+1,a+n+n+1);
	rep(i,1,2*n+1)a[i]%=mod;
	int sum=0,ans=0;
	rep(i,1,n+1)sum=add(sum,a[i]);
	rep(i,1,n+1){
		ans=sub(ans,mul(C(n,i),mul(sum,C(n-1,i-1))));
	//	cout<<mul(sum,C(n-1,i-1))<<"check\n";
	}
//	cout<<sum<<' '<<mod-ans<<"ans\n";
	sum=0;
	rep(i,n+1,2*n+1)sum=add(sum,a[i]);
	rep(i,1,n+1){
		ans=add(ans,mul(C(n,i),mul(sum,C(n-1,i-1))));
	}
	printf("%d\n",mul(ans,2));
}