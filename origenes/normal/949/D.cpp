#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123456;
int n, d, b, a[maxn];
ll s[maxn];
inline ll sum(ll L, ll R){
	return s[min(R, ll(n))]-s[max(L, 1LL)-1];
}
bool check(int k){
	for(int i=1; i<=n; i++)
		s[i]=s[i-1]+a[i];
	int L=k+1, R=n-k;
	ll cur=k, cnt=0;
	for(int i=1; i<L; i++) cnt+=a[i];
	for(int i=L; i<=n/2; i++){
		cnt+=a[i]-b;
		cur++;
		ll seg=sum(i+1, i+cur*d);
		if(seg+cnt<0) return false;
	}
	int rem=n-n/2;
	cnt=0, cur=k;
	for(int i=R+1; i<=n; i++) cnt+=a[i];
	for(int i=R; i>=rem; i--){
		cnt+=a[i]-b;
		cur++;
		ll seg=sum(i-cur*d, i-1);
		if(seg+cnt<0) return false;
	}
	return true;
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>d>>b;
	for(int i=1; i<=n; i++) cin>>a[i];
	int L=0, R=n;
	while(L<R){
		int M=L+R>>1;
		check(M)?R=M:L=M+1;
	}
	cout<<L<<endl;
	return 0;
}