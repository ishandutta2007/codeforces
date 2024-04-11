#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD = 1e9+7;

int main(){
	int n;
	cin>>n;
	vector<pll> ps(n);
	rep(i,n) cin>>ps[i].X>>ps[i].Y;
	map<ll,ll> mp;
	for(pll p:ps){
		int f=1;
		auto it=mp.upper_bound(p.X);
		if(it!=mp.end() && it->X < p.X+p.Y) f=0;
		if(it!=mp.begin()){
			--it;
			if(p.X<it->Y) f=0;
		}
		ll a,b;
		if(f){
			a=p.X; b=p.X+p.Y;
		}else{
			ll x=1;
			for(pll q:mp){
				if(x+p.Y<=q.X) break;
				x=q.Y;
			}
			a=x; b=x+p.Y;
		}
		cout<<a<<" "<<b-1<<endl;
		mp[a]=b;
	}
	return 0;
}