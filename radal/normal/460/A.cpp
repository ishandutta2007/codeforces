#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
using namespace std; 
int main() {
	ll n,m,ans=0,k2;
	cin >> n >> m;
	while (n != 0){

		ans++;
		n--;
		if (ans%m == 0 && ans != 0) n++;
	}
	cout << ans << endl;
	
}