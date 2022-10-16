#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long 
#define ld long double
#define MAX (int)(pow(10,6)+ 10)
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = 1000007;
double eps = 1e-9;
ifstream in;
ofstream out;

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};


void deal(){
	ll n, m;
	cin>>n>>m;
	vector<vector<char> > arr(n, vector<char> (m));
	fori(n){
		forj(m){
			cin>>arr[i][j];
		}
	}
	ll cnt1 = 0, cnt2 = 0;
	
	fori(n){
		ll mn = m, mx =  -1;
		forj(m){
			if(arr[i][j] == '#'){
				mn = min(mn, j);
				mx = max(mx, j);
			}
		}
		for(mn; mn<=mx; mn++){
			if(arr[i][mn]!='#'){
				cout<<-1;
				return;
			}
		}
		if(mx == -1){
			++cnt1;
		}
	}
	
	forj(m){
		ll mn = n, mx = -1;
		fori(n){
			if(arr[i][j] == '#'){
				mn = min(mn, i);
				mx = max(mx, i);
			}
		}
		for(mn; mn<=mx; mn++){
			if(arr[mn][j] != '#'){
				cout<<-1;
				return;
			}
		}
		if(mx == -1){
			++cnt2;
		}
	}
	
	if((cnt1 && !cnt2) || (cnt2 && !cnt1) ){
		cout<<-1;
		return;
	}
	
	vector<vector<bool> > seen(n, vector<bool>(m, 0));
	
	ll cnt = 0;
	fori(n){
		forj(m){
			if(!seen[i][j] && arr[i][j] == '#'){
				vector<pair<ll,ll> > bfs(1, mp(i, j));
				seen[i][j] = 1;
				fork((ll)bfs.size()){
					auto el = bfs[k];
					ll x = el.ff, y = el.ss;
					forl(4){
						ll x1 = x + dx[l], y1 = y + dy[l];
						if(x1 > -1 && y1>-1 && x1 < n && y1 < m && arr[x1][y1] == '#' && !seen[x1][y1]){
							seen[x1][y1] = 1;
							bfs.pb(mp(x1,y1));
						}
					}
				}
				++cnt;
			}
		}
	}
	
	
	
	
	cout<<cnt;
	
	
}


 

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
//	test();
	deal();
}



/* 
6 8 
1 2
2 3
3 4
4 1
2 5
3 5
1 6
4 6
*/