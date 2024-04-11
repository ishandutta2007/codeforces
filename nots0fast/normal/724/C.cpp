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
#define MAX (int)(pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

ll hsh(ll a, ll b){
	return a*MAX + b;
}
void hash_back(ll ans, ll& a, ll& b){
	a = ans/MAX;
	b = ans%MAX;
}

unordered_map<ll , unordered_map<ll,ll> > all;
ll pt[MAX][4][4];
ll sv[MAX][2];
ll Mn[MAX];

void change(ll& val){
	if(val == -1)
		val = 1;
	else
		val = -1;
}

ll tim( ll x, ll y, ll dir1 , ll dir2, ll n, ll m){
	ll mn = pow(10,18);
	if( dir1 == -1)
		mn = min(mn,x);
	else
		mn = min(mn, n-x);
	if( dir2 == -1)
		mn = min(mn,y);
	else
		mn = min(mn,m-y);
		
	return mn;
}

bool not_corner( ll x , ll y, ll n , ll m){
	if( (!x || x==n) && (!y  || y==m))
		return 0;
	return 1;
}

void deal(){
	ll n,m,k;
	cin>>n>>m>>k;
	fori(k){
		ll x, y;
		cin>>x>>y;
		sv[i][0] = x, sv[i][1] = y;
		ll cnt = 0;
		Mn[i] = pow(10,18);
		for(ll dir1 = -1; dir1<2; dir1+=2)
			for(ll dir2 = -1; dir2<2; dir2+=2){
				ll when = tim(x,y, dir1, dir2, n, m);
				pt[i][cnt][0] = x + when*dir1;
				pt[i][cnt][1] = y + when*dir2;
				
				change(dir1);
				change(dir2);
				
				when = tim(x,y, dir1, dir2, n, m );
				
				pt[i][cnt][2] = x + when*dir1;
				pt[i][cnt][3] = y + when*dir2;
				
				change(dir1);
				change(dir2);
				
				++cnt;
			}
	}
	
	ll st = 0;
	ll dir1 = 1 , dir2 = 1;
	ll x  = 0, y = 0;
	do{
		ll when = tim(x+dir1,y+dir2, dir1 ,dir2, n , m);
		++when;
//		cout<<" when "<<when<<" st: "<<st<<endl;
		ll x1 =  x +when*dir1;
		ll y1 =  y +when*dir2;
//		cout<<x<<" "<<y<<endl;
		all[hsh(x,y)][hsh(x1,y1)] = st;
		st+=when;
		x = x1, y = y1;
		if(x == 0 || x == n)
			change(dir1);
		else
			change(dir2);
	}while(not_corner(x,y,n,m));
	
	fori(k){
		forj(4){
			vector<int> lz(5);
			fork(4)
				lz[k] = pt[i][j][k];
			lz[4] = -1;
			auto it = all[hsh(pt[i][j][0], pt[i][j][1])].find(hsh(pt[i][j][2], pt[i][j][3]));
			if(it == all[hsh(pt[i][j][0], pt[i][j][1])].end())
				continue;
			ll dist = fabs(sv[i][0] - pt[i][j][0]) + (*it).ss;
			Mn[i] = min(Mn[i], dist);
		}
		if(Mn[i] == pow(10,18))
			cout<<-1<<'\n';
		else	
			cout<<Mn[i]<<'\n';
	}
	
	
	
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