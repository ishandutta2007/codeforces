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


pair<ll,ll>  offer[MAX];
ll need[MAX];
ll when[MAX]; // when transaction i is on sale ( latest )
ll day[MAX];  // how much bonus ( offer ) we have on ith day

void deal(){
	int n,m;
	cin>>n>>m;
	fori(n)
		cin>>need[i];
	fori(m){
		int d,t;
		cin>>d>>t;
		offer[i].ff = d, offer[i].ss = t-1;
	}
	int a = 0, b = pow(10,6);
	while(a<b){
		int c=  (a+b)/2;
		fori(n)
			when[i] = -1;
		fori(m)
			if(offer[i].ff <= c)
				when[offer[i].ss] = max(when[offer[i].ss], offer[i].ff );
		fori(MAX)
			day[i] = 0;
		fori(n)
			if(when[i]!=-1)
				day[when[i]] += need[i];
		ll total = 0;
		fori(n)
			total += need[i];
		ll sum 	 = 0;
		ll money = 0;
		for(int i =1 ; i<c+1; i++){
			++money;
			sum+=min(money,day[i]);
			money-=min(money,day[i]);
		}
		ll left = total - sum;
//		cout<<"total sum: "<<total<<" "<<sum<<endl;
//		cout<<"money: "<<money<<" left sum: "<<left<<endl;
		if(money >= left * 2)
			b=c;
		else
			a=c+1;
	}
	cout<<a;
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