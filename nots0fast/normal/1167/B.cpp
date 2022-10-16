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

vector<pair<int,int> > mult[MAX];

void deal(){
	int arr[6] = {4,8,16,15,23,42};
	fori(6)
		forj(i)
			mult[arr[i]*arr[j]].pb(mp(arr[i],arr[j]));
	cout<<"? 1 2"<<endl;
	int a,b;
	cin>>a;
	cout<<"? 2 3"<<endl;
	cin>>b;
	if(mult[a][0].ff == mult[b][0].ff || mult[a][0].ff == mult[b][0].ss)
		arr[1] = mult[a][0].ff;
	else
		arr[1] = mult[a][0].ss;
	arr[0] = a/arr[1];
	arr[2] = b/arr[1];
	cout<<"? 4 5"<<endl;
	cin>>a;
	cout<<"? 5 6"<<endl;
	cin>>b;
	if(mult[a][0].ff == mult[b][0].ff || mult[a][0].ff == mult[b][0].ss)
		arr[4] = mult[a][0].ff;
	else
		arr[4] = mult[a][0].ss;
	arr[3] = a/arr[4];
	arr[5] = b/arr[4];
	cout<<"! ";
	fori(6)
		cout<<arr[i]<<' ';
	cout<<endl;
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