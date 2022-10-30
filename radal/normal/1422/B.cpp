#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e2+20;
ll a[N][N];
int main(){ 
    ios:: sync_with_stdio(false); 
    string s;
    ll T;
    cin >> T;
    while (T--){
    	ll n,m;
    	cin >> n >> m;
    	rep (i,0,n){
    		rep (j,0,m){
    			cin >> a[i][j];
			}
		}
		ll ans=0,f1=0,f2=0;
		if ((n%4)%2)f1=1;
		if ((m%4)%2) f2=1;
		if (n == 1 && m == 1){
			cout << 0 << endl;
			continue;
		}
		if (n == 1){
			rep (i,0,m/2){
				ll mi = a[0][i] + a[0][m-i-1];
				mi/=2;
				ans += abs(a[0][i]-mi)+ abs(mi -a[0][m-i-1]);
			}
			cout << ans << endl;
			continue;
		}
		if (m == 1){
			rep (i,0,n/2){
				ll mi = a[i][0] + a[n-i-1][0];
				mi/=2;
				ans += abs(a[i][0]-mi)+ abs(mi -a[n-1-i][0]);
			}
			cout << ans << endl;
			continue;
		}
		rep (i,0,n/2+n%2){
			rep(j,0,m/2+m%2){
		//		cout << j << ' ';
				//debug(i);debug(j);debug(ans);
				ll x = a[i][j];
				ll y = a[n-i-1][j];
				ll z = a[n-i-1][m-1-j];
				ll v = a[i][m-1-j];
				if ((!(n%2) && !(m%2)) || ((!(n%2) || i!=n/2 ) && (!(m%2) || j!=m/2))){
				//	if (x > z) swap(x,z);
				//	if (x > v) swap (x,v);
				//	if (y > z) swap (y,z);
				//	if (y > v) swap (y,v);
				//	ll mi = (max(x,y)+min(z,v))/2;
					//debug(mi);
					ans += min(min(abs(y-x)+abs(z-x)+abs(v-x),abs(x-y)+abs(z-y)+abs(v-y)),min(abs(x-z)+abs(z-y)+abs(z-v),abs(x-v)+abs(y-v)+abs(z-v)));
				//	ans += abs(x-mi)+abs(y-mi)+abs(z-mi)+abs(v-mi);
				}
				else{
					if (n%2 && i == n/2 && j != m/2){
						//ll mi  = x+z;
						//mi /= 2;
						
						ans += abs(x-z);
					}
					if (m%2 && i != n/2 && j == m/2){
						ll mi = x+y;
						mi/=2;
						ans+=abs(x-y);
					}
					
				}
			}
		//	cout << endl;
		}
		cout << ans << endl;
		
	}

}