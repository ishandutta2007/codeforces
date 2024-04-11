#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int P = 62;
vector<ll>Q[P];
set<ll>V[P];

ll sqrt(ll u){
	ll li = 0,lr = (ll)2e9;
	ll mid;
	while(li+1<lr){
		mid = (li+lr)/2;
		if(mid * mid > u)
			lr = mid;
		else
			li = mid;
	}
	return li;
}

bool perfect(ll u){
	ll y = sqrt(u);
	if( y*y  == u)
		return true;
	else
		return false;
}

void init(){
	ll x;
	ll d;
	bool ci;
	for(ll j = 2;j<=(ll)1e6;j++){
		x=j*j;
		for(int i = 0;i<P;i++){
			d = (ll)1e18 / x;
			if(d < j){
				break;
			}
			x *= j;
			if(perfect(x)){
				continue;
			}
			ci = true;
			for(int j = 0;j<P;j++)
				if(V[j].count(x))
					ci = false;
			if(!ci)
				continue;
			V[i].insert(x);
			Q[i].push_back(x);
		}
	}
}

int main(){
	fastIO;
	init();
	int t;
	scanf("%d",&t);
	ll li = 0,ri = 0;
	ll pl , pr;
	ll ans;
	while(t--){
		scanf("%lli %lli",&li,&ri);
		ans = 0;
		pl = sqrt(li);
		if(!perfect(li))
			pl++;
		pr = sqrt(ri);
		ans += max(0LL,pr-pl+1);
		for(int i = 0;i<P;i++){
			pr = upper_bound(Q[i].begin(),Q[i].end(),ri)-Q[i].begin();
			pl = lower_bound(Q[i].begin(),Q[i].end(),li)-Q[i].begin();
			ans += pr-pl;
		}
		printf("%lli\n",ans);
	}
	return 0;
}