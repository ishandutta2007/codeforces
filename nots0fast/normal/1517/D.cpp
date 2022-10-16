#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define ll int
#define lll __int128
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(550)
#define ch (int)(500)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = { 0, 1, 0, -1};

ll wei[MAX][MAX][4];

ll seen[MAX][MAX];
ll dist[MAX][MAX];
ll distn[MAX][MAX];

void deal(){
	ll n, m, k;
	cin>>n>>m>>k;
	
	fori(n){
		forj(m){
			fork(4){
				wei[i][j][k] = inf;
			}
		}
	}
	
	fori(n){
		forj(m-1){
			ll ed;
			cin>>ed;
			wei[i][j][1] = ed;
			wei[i+dx[1]][j+dy[1]][3] = ed;
		}
	}
	
	fori(n-1){
		forj(m){
			ll ed;
			cin>>ed;
			wei[i][j][2] = ed;
			wei[i+dx[2]][j+dy[2]][0] = ed;
		}
	}
	
	
	if( k % 2 != 0){
		fori(n){
			forj(m){
				cout<<-1<<' ';
			}
			cout<<'\n';
		}
		return;
	}
	
	ll tim = 1;
	
	fori(n){
		forj(m){
			++tim;
			seen[i][j] = tim;
			dist[i][j] = 0;
			forx(k/2){
				++tim;
				ll dt = x+1;
				for(ll i1 =  i - dt; i1 <= i+dt; i1++){
					ll left = dt-fabs(i-i1);
					for(ll j1 = j -left; j1 <= j + left; j1++){
						ll curdist = fabs(j1 - j) + fabs(i - i1);
						if(i1 < 0 || j1 < 0 || i1 >= n || j1 >= m  ){
							continue;
						}
						distn[i1][j1] = inf;
						if(curdist%2==x%2){
							continue;
						}
						fory(4){
							ll i2 = i1 + dx[y], j2 = j1 + dy[y];
							if(i2 < 0 || j2 < 0 || i2 >= n || j2 >= m || seen[i2][j2]!=tim-1){
								continue;
							}
							distn[i1][j1] = min(distn[i1][j1], dist[i2][j2] + wei[i1][j1][y]);
						}
					}
				}
				
				for(ll i1 =  i - dt; i1 <= i+dt; i1++){
					ll left = dt-fabs(i-i1);
					for(ll j1 = j -left; j1 <= j + left; j1++){
						if(i1 < 0 || j1 < 0 || i1 >= n || j1 >= m){
							continue;
						}
						dist[i1][j1] = distn[i1][j1];
				//		cout<<i1+1<<" "<<j1+1<<" "<<dist[i1][j1]<<endl;
						seen[i1][j1] = tim;
					}
				}
			}
			
			ll mn = inf;
			
			{
				ll dt = k/2;
				for(ll i1 =  i - dt; i1 <= i+dt; i1++){
					ll left = dt-fabs(i-i1);
					for(ll j1 = j -left; j1 <= j + left; j1++){
						if(i1 < 0 || j1 < 0 || i1 >= n || j1 >= m){
							continue;
						}
						mn = min(mn, dist[i1][j1]);
					}
				}
			}
			
			cout<<mn*2<<' ';
		}
		cout<<'\n';
	}
	
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();  
}