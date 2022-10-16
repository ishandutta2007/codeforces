
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
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,8);
ll modulo = pow(10,9)+7  ;
#define ld long double
#define MAX (int)(pow(10,6)+ 10)

struct box{
	ll x1, y1, x2, y2;
	box(ll x1, ll y1, ll x2, ll y2) : x1(x1), y1(y1), x2(x2), y2(y2){}
	box(){}
	void intersect(box& other){
		x1 = max(x1, other.x1);
		x2 = min(x2, other.x2);
		y1 = max(y1, other.y1);
		y2 = min(y2, other.y2);
	}
};

ll arr[MAX];

void deal(){
	ll q;
	cin>>q;
	forl(q){
		box ini(-pow(10,5), -pow(10,5), pow(10,5), pow(10,5));
		ll n;
		cin>>n;
		fori(n){
			ll x, y;
			cin>>x>>y;
			box cur(-pow(10,5), -pow(10,5), pow(10,5), pow(10,5));
			ll fs[4];
			forj(4)
				cin>>fs[j];
			if(!fs[0])
				cur.x1 = x;
			if(!fs[1])
				cur.y2 = y;
			if(!fs[2])
				cur.x2 = x;
			if(!fs[3])
				cur.y1 = y;
			ini.intersect(cur);
	//		cout<<ini.x1<<" "<<ini.x2<<" "<<ini.y1<<" "<<ini.y2<<endl;
		}
		if(ini.x1 <= ini.x2 && ini.y1 <= ini.y2)
			cout<<"1 "<<ini.x1<<" "<<ini.y1<<'\n';
		else
			cout<<"0\n";
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
/*
 
5 1
1 2 3 4 5


*/