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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 1000000007;

ll arr[MAX];
ll fen [MAX][2];
void upd(ll ind, ll kd , ll vl){
	while(ind<MAX)
		fen[ind][kd]+=vl, ind+=ind&-ind;
}
ll que(ll ind, ll kd){
	ll s= 0;
	while(ind)	s+=fen[ind][kd], ind-=ind&-ind;
	return s;
}


void deal(){
	ll n, t;
	cin>>n>>t;
	ll mn = inf;
	fori(n){
		ll ed;
		cin>>ed;
		arr[i+1] = ed;
		mn = min(mn, ed);
		upd(i+1, 0, ed);
		upd(i+1, 1, 1);
	}
	// t is curmoney
	// storing prefix sums at fenwick tree
	ll answer = 0;
	while(t>=mn){
	//	cout<<"the t "<<t<<endl;
		ll cur_sum = que(n, 0);
		ll when = t/cur_sum;
		if(when!=0)
			--when;
	//	cout<<" when we fucked up "<<when<<" with cur_sum "<<cur_sum<<endl;
		answer+=que(n,1)*when;
		t     -=cur_sum*when;
		ll lef = 1;
		while(lef <= n){
			ll slef = lef, srig = n;
			ll mx_sum = que(n, 0) - que(lef-1, 0);
			if(mx_sum <= t){
				t -= mx_sum;
				answer  += que(n,1) - que(lef-1,1);
				break;
			}
			while(srig > slef){
				ll mid = (slef + srig) / 2;
				ll sum =  que(mid,0) - que(lef-1, 0);
				if( sum > t)
					srig = mid;
				else
					slef = mid+1;
			}
			// slef is first point where it fucks up
		//	cout<<"we fuck up at slef "<<slef<<endl;
			upd( slef , 0, -arr[slef]);
			upd( slef,  1, -1);
			t -= que(slef-1,0) - que(lef-1,0);
			answer+= que(slef-1, 1) - que(lef-1,1);
			lef = slef+1;
		} 
		
	}
	cout<<answer;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1