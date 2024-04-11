#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
using namespace std; 
const int N=2e6;
set <ll> pos,neg;
pair <ll,ll> c[N];
ll a[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	ll n ,t;
	cin >> n >> t;
	if (n == 1 && t == 10){
		cout << -1;
		return 0;
	}
	else{
		cout << t;
		if (t<10){
			rep(i,0,n-1){
				cout << '0';
			}
		}
		else{
			rep(i,0,n-2) cout<<'0';
		}
	}
	return 0;
}