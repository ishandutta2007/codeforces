#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(ll i=l; i<r; i++)
#define repr(i,r,l) for(ll i=r; i>=l; --i)
#define pb push_back
#define mp make_pair
#define Y second
#define X first
using namespace std; 
const long long int mod=1e8,N=1e5+10;
ll a[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cout.tie(0);
	ll n;
	cin >> n;
	rep (i,0,n){
		ll x;
		cin >> x;
		a[x-1]++;
	}
	ll t2=0,t4=0,t6=0,t8=0;
	ll q;
	cin >> q;
	rep (i,0,N){
		if (a[i] >= 2) t2++;
		if (a[i] >= 4) t4++;
		if (a[i] >= 6) t6++;
		if (a[i] >= 8) t8++;
	}
	/*if (t8 || (t6 && t2 >= 2) || (t4 && t2 >=3)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO"<<endl;
	}*/
	rep (i,0,q){
		char s;
		ll r;
		cin >> s >> r;
		r--;
		if (s == '-'){
			a[r]--;
			if (a[r] == 7) t8--;
			if (a[r] == 3) t4--;
			if (a[r] == 5) t6--;
			if (a[r] == 1) t2--;
		}
		else{
			a[r]++;
			if (a[r] == 8) t8++;
			if (a[r] == 4) t4++;
			if (a[r] == 6) t6++;
			if (a[r] == 2) t2++;
			
		}
		if (t8 || (t6 && t2 >= 2) || (t4 && t2 >=3) || t4 >= 2){
			cout << "YES" << endl;
		}
		else{
			cout << "NO"<<endl;
		}
	}
	
}