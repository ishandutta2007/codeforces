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
#define MAX 1000100
#define pb(a) push_back(a)
#define M 1000
#define N 100100
#define MAXN 1000001
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,13);
ll modulo = pow(10,9) + 7;
ll arr[MAX];
namespace dsu{
	ll aid[MAX];
	vector<ll> dsu[MAX];
	ll mx[MAX];
	ll mn[MAX];
	ll sum;
	ll entr;
	void init(int n){
		sum = n, entr = n;
		fori(n)
			aid[i] = i, dsu[i].push_back(i), mx[i] = arr[i], mn[i] = arr[i];
	}
	void join(ll a,ll b){
	//	cout<<"joinin "<<a<<" and "<<b<<endl;
		ll aid1 = aid[a], aid2 = aid[b];
		if(dsu[aid2].size() > dsu[aid1].size()){
			ll temp  = aid1;
			aid1 = aid2, aid2 = temp;
		}
		if(aid1==aid2)
			return;
	//	cout<<"sum was : "<<sum<<" ";
		--entr;
		sum-=(mx[aid1]-mn[aid1]+1) + (mx[aid2]-mn[aid2]+1);
		mx[aid1] = max(mx[aid1], mx[aid2]);
		mn[aid1] = min(mn[aid1], mn[aid2]);
		sum+=mx[aid1]-mn[aid1]+1;
	//	cout<<"sum became  "<<sum<<endl;
//		cout<<"num  of entries "<<entr<<endl;
		fori(dsu[aid2].size()){
			int hd = dsu[aid2][i];
			aid[hd] = aid1;
			dsu[aid1].push_back(hd);
		}
		dsu[aid2].clear();
	}
};
vector<pair<ll,ll> > events;
bool J(pair<ll,ll>& a , pair<ll,ll>& b){
	return a.ss < b.ss;
}
bool J1(vector<ll>& a, vector<ll>& b){
	return a[1] - a[0] < b[1] - b[0];
}
ll answers[MAX];
vector<vector<ll> > que;
void deal(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n;
	cin>>n;
	fori(n)
		cin>>arr[i];
	sort(arr, arr+n);
	fori(n-1)
		events.pb(mp(i, (arr[i+1]-arr[i])));
	sort(events.begin(), events.end(), J);
	ll q;
	cin>>q;
	fori(q){
		ll a, b;
		cin>>a>>b;
		vector<ll> quer(3);
		quer[0] = a, quer[1] = b, quer[2] = i;
		que.pb(quer);
	}
	sort(que.begin(), que.end(), J1);
	dsu::init(n);
	ll pt  = 0;
	fori(que.size()){
		ll tim = que[i][1] - que[i][0];
	//	cout<<"time "<<tim<<endl;
		while( pt<events.size() && events[pt].ss <= tim)
			dsu::join(events[pt].ff, events[pt].ff + 1), ++pt;
//		cout<<tim<<" "<<dsu::entr<<" "<<dsu::sum<<endl;
		answers[que[i][2]] = dsu::sum+dsu::entr*tim;
	}
	fori(q)
		cout<<answers[i]<<' ';
}
int main(){
    deal();
}