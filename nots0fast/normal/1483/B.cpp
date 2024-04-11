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
		ll n;
		cin>>n;
		vector<ll> arr(n);
		fori(n){
			cin>>arr[i];
		}
		
		set<ll> stillThere;
		set<ll> gcdOne;
		fori(n){
			ll gcd = __gcd(arr[i], arr[(i+n-1)%n]);
			if(gcd == 1){
				gcdOne.insert(i);
			}
			stillThere.insert(i);
		}
		
		ll lst = 1;
		
		vector<ll> order;
		while(gcdOne.size()){
			auto it = gcdOne.lower_bound(lst);
			if(it == gcdOne.end()){
				it = gcdOne.begin();
			}
			
			auto which = *it;
			
			gcdOne.erase(it);
			
			it = stillThere.find(which);
			
			
			auto itn = it, itb = it;
			
			if(itb!=stillThere.begin()){
				--itb;
			}
			else{
				itb = stillThere.end();
				--itb;
			}
			
			++itn;
			if(itn == stillThere.end()){
				itn = stillThere.begin();
			}
			
			order.pb(*it);
			
			stillThere.erase(it);
			
			if((ll)stillThere.size()!=0){
				ll pv = *itb, nx = *itn;
				ll gcd = __gcd(arr[pv], arr[nx]);
				
				if(gcdOne.find(nx) != gcdOne.end()){
					gcdOne.erase(nx);
				}
				
				if(gcd == 1){
					gcdOne.insert(nx);
				}
				
				auto itnn = itn;
				
				++itnn;
				if(itnn==stillThere.end()){
					itnn = stillThere.begin();
				}
				
				lst = *itnn;
				
			}
			
			
			
		}
		
		cout<<order.size()<<' ';
		fori((ll)order.size()){
			cout<<order[i]+1<<' ';
		}
		cout<<'\n';
		
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