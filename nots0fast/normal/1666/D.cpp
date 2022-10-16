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
	ll t;
	cin>>t;
	forl(t){
		string a, b;
		cin>>a>>b;
		ll pv = a.length()-1;
		vector<bool> seen(26, 0);
		
		bool gg = 1;
		for(ll j = (ll)b.length() -1; j>=0 ; j-- ){
			if(seen[b[j] - 'A']){
				gg = 0;
			}
			while(pv > -1 && a[pv]!=b[j]){
				seen[a[pv] - 'A'] = 1;
				--pv;
			}
			if(pv == -1){
				gg = 0;
			}
			--pv;
		}
		
		if(!gg){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
}
    

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}