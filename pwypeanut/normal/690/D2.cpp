#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define M 1000003ll
ll fac[1000005],inv[1000005];
ll expo(ll a,ll b) {
	if (!b) return 1ll;
	ll x=expo(a,b/2ll);
	if (b%2ll) return (((x*x)%M)*a)%M;
	return (x*x)%M;
}
ll ch(int a,int b) {
	return (((fac[a]*inv[b])%M)*inv[a-b])%M;
}
int main() {
	fac[0]=inv[0]=1ll;
	for (int i=1;i<=800000;i++) {
		fac[i]=(fac[i-1]*(ll)i)%M;
		inv[i]=expo(fac[i],M-2ll);
	}
	int a,b;
	scanf("%d%d",&a,&b);
	ll ans=0ll;
	for (int i=1;i<=a;i++) {
		ans+=ch(i+b-1,b-1);
		ans%=M;
	}
	cout<<ans<<endl;
}