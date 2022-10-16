#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define ll int
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 9);
ll modulo = pow(10, 9) + 7;
double eps = 1e-10;
ifstream in;
ofstream out;




ll maxsize(vector<vector<ll> >& pos, ll x, ll y, ll dt, vector<vector<ll> >& need){
	vector<ll> tot(70, 0);
	
	for(auto& el : pos){
		ll s = 0;
		for(ll j = 0; j<2; j++){
			ll xi = el[j*2], yi = el[j*2 + 1];
			s += abs(x- xi) + abs(y - yi);
		}
		if(s == dt){
			need.pb(el);
		}
		tot[s]++;
	}
	
	ll mx = -1;
	fori(70){
		mx = max(mx, tot[i]);
	}
	return mx;
}

bool debug = 0;

void deal(){
	vector<vector<ll>> tests;
	ll testn = 16, testm = 16;
	
	for(ll i = 1; i<=testn; i++){
		for(ll j = 1; j<=testm; j++){
			for(ll k = 2; k<=testn; k++){
				for(ll y = 1; y<=testm; y++){
					if(mp(i, j) < mp(k, y)){
						tests.pb(vector<ll>({i, j, k, y}));
					}
				}
			}
		}
	}
	
	
	ll t;
	if(!debug){
		cin>>t;
	}
	else{
		t = tests.size();
	}
	forl(t){
		ll n, m;
		if(!debug){
			cin>>n>>m;
		}
		else{
			n = testn, m = testm;
		}
		vector<vector<ll> > pos;
		for(ll i1 = 1; i1<=n; i1++){
			for(ll j1 = 1; j1<=m; j1++){
				for(ll i2 = 1; i2<=n; i2++){
					for(ll j2 = 1; j2<=m; j2++){
						if(mp(i1, j1) < mp(i2, j2)){
							pos.pb(vector<ll>({i1, j1, i2, j2}));
						}
					}
				}
			}
		}
		if(debug){
			cout<<"treasure ";
			forj(4){
				cout<<tests[l][j]<<' ';
			}
			cout<<endl;
		}
		
		ll total = 0;
		
		while(1){
			ll mn = inf;
			ll xn = -1 , yn  = -1;
			for(ll i =1 ; i<=n; i++){
				for(ll j = 1; j<=m; j++){
					vector<vector<ll> > cur;
					ll curmax = maxsize(pos, i, j, -1, cur);
					if(curmax < mn){
						mn = curmax;
						xn = i, yn = j;
					}
				}
			}
			if(mn == (ll)pos.size()){
				break;
			}
			
		//	cout<<"maxsize is "<<mn<<endl;
			if(!debug){
				cout<<"SCAN "<<xn<<" "<<yn<<endl;
			}
			++total;
			ll dt;
		
			if(!debug){
				cin>>dt;
			}
			else{
				dt = abs(tests[l][0] - xn) + abs(tests[l][1] - yn) + abs(tests[l][2]  - xn) + abs(tests[l][3]  - yn);
			}
			
			
			
			vector<vector<ll> > cur;
			maxsize(pos, xn, yn, dt, cur);
			
			pos = cur;
			if(debug){
				cout<<"we checked "<<xn<<" "<<yn<<" new size "<<pos.size()<<endl;
				if(pos.size() >= 2){
					cout<<"first 2"<<endl;
					fork(2){
						forj(4){
							cout<<pos[k][j]<<' ';
						}
						cout<<endl;
					}
				}
			}
			
		}
		
		if(debug && (ll)pos.size() > 1){
			cout<<"it was test ";
			forj(4){
				cout<<tests[l][j]<<' ';
			}
			cout<<endl;
		}
		
		// assert((ll)pos.size() == 1);
		
		if(!debug){
			
			map<ll, map<ll, ll> > bad;
			map<ll, map<ll, ll> > good;
			
			ll tot = 0;
			for(auto &el : pos){
				if(bad[el[0]][el[1]] || bad[el[2]][el[3]]){
					continue;
				}
				for(ll k = 0; k<2; k++){
					ll xi = el[2*k], yi  =el[2*k+1];
					if(good[xi][yi]){
						continue;
					}
					assert(total < 7);
					cout<<"DIG "<<xi<<" "<<yi<<endl;
					++total;
					ll vl ;
					cin>>vl;
					if(vl == 1){
						++tot;
						good[xi][yi] = 1;
					}
					else{
						bad[xi][yi] = 1;
						break;
					}
					if(tot == 2){
						break;
					}
				}
			
				if(tot == 2){
					break;
				}
			}
			
			
		}
		
	}
	
}
    

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}