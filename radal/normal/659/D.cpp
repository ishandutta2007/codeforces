#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
#define F first
#define S	second
using namespace std; 
const int N=1e2;
set <ll> pos,neg;
pair <ll,ll> c[N];
char a[N][N];
int main(){
	pair <ll,ll> co;
	ll n,ans=0;
	char dir='u';
	cin >> n;
	rep(i,0,n+1){
		ll x,y;
		cin >> x >> y;
		if (i > 0){
			if (y-co.S > 0){
				if (dir == 'r'){
					ans++;
				}
				dir = 'u';
	//			cout << y-co.S<<endl;
			}
			if (y-co.S < 0){
				if (dir == 'l'){
					ans++;
				}
				dir = 'd';
			}
			if (x-co.F > 0){
				if (dir == 'd'){
					ans++;
				}
				dir = 'r';
			}
			if (x-co.F < 0){
				if (dir == 'u'){
					ans++;
				}
				dir = 'l';
			}
		}
		co.F = x;
		co.S = y;
	//	cout << i << " ans : " << ans << endl;
	}
	cout << ans << endl;
	return 0;
}