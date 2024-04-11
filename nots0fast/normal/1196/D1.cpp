
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
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,8);
ll modulo = pow(10,9)+7  ;
#define ld long double
#define MAX (int)(pow(10,6)+ 10)



void deal(){
	ll q;
	cin>>q;
	forl(q){
		ll n , k;
		cin>>n>>k;
		string nd = "RGB";
		vector<char> arr(n+3);
		vector<vector<ll> > 	  dp(3, vector<ll> (n+3, 0));
		fori(n)
			cin>>arr[i+3];
		fori(3)
			forj(3)
				dp[i][j] = 0;
		for(ll i =3; i<n+3; i++){
			forj(3)
				dp[j][i] = dp[j][i-3];
			dp[nd.find(arr[i])][i]++;
		}
		ll mn = n;
		for(ll i = 3; i<n-k+1+3; i++){
			vector<ll> th({0,1,2});
		//	cout<<"we at "<<i<<endl;
			do{
				ll s = 0;
				forx(3){
					ll st = i + x;
					if(st >= i+k)
						break;
					ll lo = 0, hi = n;
					while(lo < hi){
						ll mid = (lo+hi)/2 +1;
						if(st+mid*3 >= i + k)
							hi = mid-1;
						else
							lo = mid;
					}
					s+=dp[th[x]][st+lo*3] - dp[th[x]][st-3];
				}
				mn = min(mn, k - s);
				swap(th[2],th[1]);
				swap(th[1], th[0]);
			}while(th[0]!=0);
		}
		cout<<mn<<'\n';
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
/*
 
5 1
1 2 3 4 5


*/