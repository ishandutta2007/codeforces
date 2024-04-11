#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
using namespace std; 
int main() {
	ll k,r,ans=1,k2;
	cin >> k >> r;
	k2 = k;
	while (k%10 != r && k%10 != 0){
		ans++;
		k+=k2;
	}
	cout << ans << endl;
	
}