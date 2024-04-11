#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(3*pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18)+10;
ll modulo = 10056;





void deal(){
	ll n;
	cin>>n;
	ll dp[10];
	fori(10)
		dp[i] = -inf;
	dp[0] = 0; // have to pick 10 to double it, dp[9]  - have to pick 1 
	fori(n){
		ll newdp[10];
		fori(10)
			newdp[i] = dp[i];
		ll dp1[4][4][2] ; // num of cards picked, sum of costs, doubled1 exists : no yes
		fori(4)
			forj(4)
				fork(2)
					dp1[i][j][k] = -inf;
		dp1[0][0][0] = 0;
		ll ki;
		cin>>ki;
		fori(ki){
			ll c, d;
			cin>>c>>d;
			for(ll j = 2; j>-1; j--)
				for(ll k = 2; k>-1; k--){
					if(k+c > 3)
						continue;
					dp1[j+1][k+c][0] = max(dp1[j+1][k+c][0], dp1[j][k][0] + d);
					dp1[j+1][k+c][1] = max(dp1[j+1][k+c][1], max(dp1[j][k][0] + d*2, dp1[j][k][1] + d));
				}
		}
			fori(10)
				forj(4)
					fork(4)
						forx(2){
							if( (i+j>=10) != x)
								continue;
							newdp[(i+j)%10] = max(newdp[(i+j)%10], dp[i] + dp1[j][k][x]);
						}
	//	cout<<"new batch"<<endl;
		fori(10){
			dp[i] = newdp[i];
	//		cout<<dp[i]<<" ";
		}
	//	cout<<endl;
	}
	fori(10)
		dp[0] = max(dp[0], dp[i]);
	cout<<dp[0];
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1