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
#define double long double
#define MAX 2000100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;


ll arr[MAX];
bool seen[MAX];

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		fori(MAX)
			seen[i]  =0;
		fori(n)
			cin>>arr[i],seen[arr[i]] = 1;
		sort(arr,arr+n);
		ll ed = arr[0] * arr[n-1];
		ll kok = sqrt(ed);
		bool fucked = 0;
		ll say = 0;
		for(ll i = 2; i<=kok; i++){
			if(!(ed%i)){
				if(!seen[i] || (ed/i >= MAX) || !seen[ed/i])
					fucked = 1;
				if(i!=ed/i)
					say+=2;
				else
					++say;	
			}
		}
		if(say!=n)
			fucked = 1;
		if(fucked)
			cout<<-1<<'\n';
		else
			cout<<ed<<'\n';
	}
}



int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}





/* 
1
7 
...O...
..O.O..
.O.O.O.
O.O.O.O
.....O.
.......
.......




*/