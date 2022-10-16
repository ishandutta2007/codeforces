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
#define MAX 2020
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9) + 7;


void deal(){
	int n;
	cin>>n;
	int a = 0, b = pow(10,9);
	if(n==1){
		cout<<0<<" "<<0<<endl;
		string z;
		cin>>z;
		cout<<0<<" "<<1<<" "<<1<<" "<<1<<endl;
		return;
	}
	string sv;
	cout<<10<<" "<<10<<endl;
	cin>>sv;
	cout<<0<<" "<<a<<endl;
	string prev ;
	cin>>prev;
	fori(n-2){
		cout<<0<<" "<<(a+b)/2<<endl;
		string col;
		cin>>col;
		if(col == prev)
			a=(a+b)/2;
		else
			b=(a+b)/2;
	}
	assert(a<b-1);
	if(prev==sv)	
		cout<<10<<" "<<11<<" "<<0<<" "<<a+1<<endl;
	else
		cout<<10<<" "<<9<<" "<<0<<" "<<a+1<<endl;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





/* 
11 9 10
1 2
2 3
3 4
4 5
5 6
6 7
4 8
8 9
8 10 
8 11

*/