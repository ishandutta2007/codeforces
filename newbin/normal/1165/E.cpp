#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 2e5 + 50;
const ll mod = 998244353;
ll a[maxn],b[maxn];
int n;
int main(){
	int n;cin>>n;
	for(int i = 1;i <= n;++i) {
		scanf("%I64d",&a[i]);
		a[i] = a[i]*(ll)i*(n-i+1);
	}
	for(int i = 1;i <= n;++i) scanf("%I64d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	ll ans = 0;
	for(int i = 1;i <= n;++i) ans = ( ans + a[i]%mod*b[n+1-i]%mod)%mod;
	cout<<ans<<endl;
}