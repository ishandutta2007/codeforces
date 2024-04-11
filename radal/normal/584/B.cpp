#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
using namespace std; 
const long long int N=1e9+7;
///set <ll> pos,neg;
//pair <ll,ll> c[N];
//ll a[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	ll n ,ans=1,t=1,t2=1;
	cin >> n;
	ll c=0;
	while (c < 3*n){
		c++;
		t*=3;
		t%=N;
	}
	c = 0;
	while (c < n){
		t2*=7;
		c++;
		t2%=N;
	}
	if (t<t2){
		t+=N;
		cout << (t-t2)%N;
		return 0;
	}
	//cout << t-t2<<endl;
	ans = pow(3,3*n)-pow(7,n);
	//cout << t2<<' '<<t <<' '<<ans%N<< endl;
	cout << max(ans%N,t-t2);
	return 0;
}