#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/*void msort(int l,int r,int* a){
	int b[10000];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid, a);
	msort(mid, r, a);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}*/

const int N=2e5;
int main(){
	ll t;
	cin >> t;
	for (ll k=0; k<t; k++){
		ll n,te = 0,to = 0,ans = 0;
		cin >> n;
		ll a[n];
		for (ll i=0; i<n; i++){
			cin >> a[i];
			if (a[i]%2) to++;
			else te++;
			if (a[i]%2 != i%2) ans++;
		}
		if (ans%2 || (to > te || te-to > 1)){
			cout << -1 <<endl;
			continue;
		}
		cout<<ans/2<<endl;
	}
}