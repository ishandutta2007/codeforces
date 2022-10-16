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

ll dx[4] = {1,-1, 0, 0};
ll dy[4] = {0, 0,-1, 1};
char  arr[MAX][MAX];
ll    Mn[MAX][MAX];

ll hsh(ll x, ll y){ // hash
	return x*MAX+y;
}

void hash_back(ll ans, ll& x, ll& y){
	x  = ans/MAX;
	y = ans%MAX;
}

void deal(){
	ll n, m, r, c, x, y;
	cin>>n>>m>>r>>c>>x>>y; --r, --c;
	fori(MAX)
		forj(MAX)
			Mn[i][j] = pow(10,16);
	fori(n)
		forj(m)
			cin>>arr[i][j];
	deque<ll> bfs(1, hsh(r,c));
	Mn[r][c] = 0;
	while(bfs.size()){
		ll x,y;
		ll ans = bfs.front();
		bfs.pop_front();
		hash_back(ans, x, y);
		fori(4){
			ll x1 = x + dx[i], y1 = y+ dy[i];
			ll cost = i/2;
			if(x1 > -1 && y1>-1 && x1<n && y1<m && arr[x1][y1]!='*' && Mn[x][y] + cost < Mn[x1][y1]){
				Mn[x1][y1] = Mn[x][y] + cost;
				if(cost)
					bfs.push_back(hsh(x1,y1));
				else
					bfs.push_front(hsh(x1,y1));
			}
		}
	}
	ll say = 0;
	fori(n)
		forj(m){
		//	cout<<"at cell "<<i+1<<" "<<j+1<<" Mn: "<<Mn[i][j]<<endl;
			ll dif  = fabs(c-j);
			ll left = (Mn[i][j] - dif)/2;
			ll right = left;
			if(c > j)
				left += dif;
			else
				right  += dif;
		//	cout<<"left right "<<left<<" "<<right<<endl;
			if(left <= x && right <= y)
				++say;	
		}
	cout<<say;
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