/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/

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
#define ll int
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,9);
ll modulo = 1000007;
double eps = 1e-6;
ifstream in;
ofstream out;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		bool yes = 0;
		set<string> seen;
		vector<string> arr;
		fori(n){
			string cur ;
			cin>>cur;
			if(cur.length() == 1){
				yes = 1;
			}
			else{
				arr.pb(cur);
			}
		}
		fori((ll)arr.size()){
			string cr = arr[i];
			seen.insert(cr);
			string rev = cr;
			reverse(rev.begin(), rev.end());
			if(seen.find(rev)!=seen.end()){
				yes = 1;
			}
			else{
				if(cr.length() == 2){
					for(char f = 'a'; f<='z'; f++){
						string rev = cr;
						reverse(rev.begin(), rev.end());
						rev += f;
						if(seen.find(rev)!=seen.end()){
							yes = 1;
						}
					}
				}
				else{
					string rev = cr;
					reverse(rev.begin(), rev.end());
					rev.erase(rev.end()-1);
					if(seen.find(rev)!=seen.end()){
						yes = 1;
					}	
				}
			}
		}
		if(yes){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}