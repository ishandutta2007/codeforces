#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long 
#define MAX (int)(pow(10,5)+ 10)
#define pb(a) push_back(a)
#define ld long double
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = 1000007;
double eps = 1e-6;
ifstream in;
ofstream out;



void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m ;
		cin>>n>>m;
		vector<ll> choice(m);
		vector<ll> tot(n, 0);
		vector<vector<ll> > all(m);
		fori(m){
			ll ki;
			cin>>ki;
			all[i].resize(ki);
			forj(ki){
				cin>>all[i][j];
				--all[i][j];
			}
			choice[i] = all[i][0];
			tot[choice[i]]++;
		}
		
		ll maxAllowed = (m+1)/2;
		
		ll wh = 0;
		fori(n){
			if(tot[i] > maxAllowed){
				wh = i;
			}
		}
		
		fori(m){
			if(tot[wh] > maxAllowed && choice[i] == wh && (ll)all[i].size() > 1){
				choice[i] = all[i][1];
				--tot[wh];
			}
		}
		
		if(tot[wh] <= maxAllowed){
			cout<<"YES\n";
			fori(m){
				cout<<choice[i]+1<<' ';
			}
			cout<<'\n';
		}
		else{
			cout<<"NO\n";
		}
		
		
	}
}
 
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
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