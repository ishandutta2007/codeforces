#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long
#define double long double
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = inf;
#define lll __int_128
double eps = 1e-10;
ifstream in;
ofstream out;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		ll fc1 = n;
		ll fc2 = 2;
		while(fc1 % 2 == 0){
			fc2 *= 2;
			fc1 /= 2;
		}
		
		
		if(fc1 == 1){
			cout<<-1<<'\n';
			continue;
		}
		
		// check fc1 or fc2
		
		// fc1 * (fc1 + 1)/ 2 <= n
		
		if((fc1 + 1)/2 <= n/fc1){
			cout<<fc1;
		}
		else{
			// fc2 * (fc2 + 1)/2 <= n
			if( (fc2 + 1) <=  n/(fc2/2) ){
				cout<<fc2;
			}
			else{
				cout<<-1;
			}
		}
		cout<<'\n';
	}
}
	

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}