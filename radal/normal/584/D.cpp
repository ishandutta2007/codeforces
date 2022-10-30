#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
using namespace std; 
const long long int N=1e5;
 
ll a[3];
ll t=0;
bool prime (ll n){
	if (n==2) return 1;
	if (n==1) return 0;
	rep (i,2,sqrt(n)+1){
		if (n%i == 0){
			return 0;
		}
	}
	return 1;
}
int solver(ll n){
	if (n==0){
		return 0;
	}
	if (t == 2 and !prime(n)){
		t--;
		return -1;
	}
	repr(i,n,2){
		//cout << i << " : " <<prime(i)<<endl;;
		if (prime(i) && n-i != 1 && (t < 1 || prime(n-i))){
			a[t] = i;
			t++;
			solver(n-i);
			break;
		}
	}
}
///set <ll> pos,neg;
//pair <ll,ll> c[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	ll n;
	cin >> n;
	solver(n);
	if (t == 4) t--;
	cout << t << endl;
	rep (i,0,t){
		cout << a[i] << ' ';
	}
	return 0;
}