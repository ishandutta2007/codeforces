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
#define ll long long
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 12);
ll modulo = pow(10, 9) + 7;
double eps = 1e-10;
ifstream in;
ofstream out;


void deal(){
	ll x1, y1, x2, y2, x3, y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	if(x2 < x1){
		swap(x1, x2);
		swap(y1, y2);
	}
	if(x3 < x1){
		swap(x1, x3);
		swap(y1, y3);
	}
	if(x3 < x2){
		swap(x2, x3);
		swap(y2, y3);
	}
	vector<vector<ll> > ans;
	ans.pb(vector<ll>({x1, y1, x2, y1}));
	ans.pb(vector<ll>({x2, y1, x2, y2}));
	if(y3 >= min(y1, y2) && y3 <= max(y1, y2)){
		ans.pb(vector<ll>({x2, y3, x3, y3}));
	}
	else if(y3 < min(y1, y2)){
		ans.pb(vector<ll>({x2, min(y1, y2), x3, min(y1, y2)}));
		ans.pb(vector<ll>({x3, min(y1, y2), x3, y3}));
	}
	else if(y3 > max(y1, y2)){
		ans.pb(vector<ll>({x2, max(y1, y2), x3, max(y1, y2)}));
		ans.pb(vector<ll>({x3, max(y1, y2), x3, y3}));
	}
	else{
		assert(0);
	}
	
	cout<<ans.size()<<'\n';
	for(auto& el : ans){
		forj(4){
			cout<<el[j]<<' ';
		}
		cout<<'\n';
	}
}
    

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}