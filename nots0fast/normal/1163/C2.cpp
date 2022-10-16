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
#define MAX 200100
#define MAX2 220
#define pb(a) push_back(a)
double eps = 1e-12;
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

map<int,vector<int> > all[MAX];
int pt[MAX][2];
int gcd(int a,int b){
	return (!b)? a : gcd(b, a%b);
}
void deal(){
	int n;
	cin>>n;
	fori(n)
		forj(2)
			cin>>pt[i][j];
	fori(n)
		forj(i){
			int dx = pt[i][0]-pt[j][0];
			int dy = pt[i][1]-pt[j][1];
			if(dx < 0)
				dx *= -1, dy*= -1;
			if(dx && dy){
				int ebob = gcd(dx, (int)fabs(dy));
				dx /= ebob, dy/=ebob;
			}
			int c  = -dy*pt[i][0] + dx*pt[i][1];
			if(!dx)
				dy = 0, c = pt[i][0];
			else if(!dy)
				dx = MAX-1, c = pt[i][1];
			all[dx][dy].pb(c);
		}
	ll sum    = 0;
	ll so_far = 0;
	fori(MAX){
		for(auto mp : all[i]){
	//		cout<<"so we at dx: "<<i<<"   dy:  "<<mp.ff<<endl;
			ll nece = 0;
			int pv   = -inf;
			sort(mp.ss.begin(), mp.ss.end());
			for(auto num : mp.ss)
				if(num != pv)
					pv = num, ++nece;
			sum += so_far * nece;
			so_far += nece;
		}
	}
	cout<<sum;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}