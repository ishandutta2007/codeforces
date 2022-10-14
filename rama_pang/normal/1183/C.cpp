#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define db(x) cout << ">>>>>>>>>>>>>" << #x << " "<< x << endl
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main (){
	IOS;
	ll q,k,n,a,b;
	cin>>q;
	while (q--){
		cin>>k>>n>>a>>b;
		if (k>n*b){
			ll s= k-n*b;
			ll diff=a-b;
			s=(s-1)/diff;
			if (s>n){
				cout << n << endl;
				continue;
			}
			cout <<s <<endl;
		} else{
			cout << -1 << endl;
		}
	}
	
}