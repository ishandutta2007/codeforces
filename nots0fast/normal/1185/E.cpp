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
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 7;
#define MAX (int)(3*pow(10,3) + 10)

char arr[MAX][MAX];
char ans[MAX][MAX];


void deal(){	 // 1 printed one , 0 - meant message
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		vector<vector<ll> > snakes;
		fori(n)
			forj(m)
				cin>>arr[i][j];
			fori(n)
				forj(m)
					ans[i][j] = '0';
			bool still_fucked = 0;
				for(ll j=25; j>-1; j--){
					ll MnMx[2][2] = { {inf, -1}, {inf, -1}};
					forx(n)
						fory(m){
							if(arr[x][y] == (char)('a'+j) ){
								ll current[2] = {x, y};
								fork(2){
									MnMx[k][0] = min(current[k], MnMx[k][0]);
									MnMx[k][1] = max(current[k], MnMx[k][1]);
								}
							}
						}
					if(MnMx[0][0]!=MnMx[0][1] && MnMx[1][0] != MnMx[1][1]){
						still_fucked |= (MnMx[0][0]!=inf);
						if(snakes.size())
							snakes.pb(snakes[snakes.size()-1]);
						continue;
					}
					bool fucked = 0;
					for(ll x = MnMx[0][0]; x<= MnMx[0][1]; x++)
						for(ll y = MnMx[1][0]; y<=MnMx[1][1]; y++){
							if(arr[x][y]!=(char)('a'+j) && ans[x][y] == '0'){
								fucked = 1;
							}
						}
					still_fucked |= fucked;
					if(fucked)
						continue;
					vector<ll> sauder;
					forx(2)
						fory(2)
							sauder.pb(MnMx[x][y]);
					swap(sauder[1], sauder[2]);
					snakes.pb(sauder);
					for(ll x = MnMx[0][0]; x<= MnMx[0][1]; x++)
						for(ll y = MnMx[1][0]; y<=MnMx[1][1]; y++){
							arr[x][y] = '0';
							ans[x][y] = '1';
						}
				}
			if(still_fucked){
				cout<<"NO\n";
				continue;
			}
			cout<<"YES\n"<<snakes.size()<<'\n';
			reverse(snakes.begin(), snakes.end());
			fori(snakes.size()){
				forj(4){
					cout<<snakes[i][j]+1<<' ';
				}
				cout<<'\n';
			}
	}
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}