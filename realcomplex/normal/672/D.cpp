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

const int N = (int)5e5 + 9;
ll w[N];
int n;
ll k;

bool maxm(ll u){
	ll s = 0;
	for(int i = 1;i<=n;i++)
		s += max(0LL,u - w[i]);
	return s <= k;
}

bool minm(ll u){
	ll s = 0;
	for(int i = 1;i<=n;i++)
		s += max(0LL,w[i] - u);
	return s <= k;
}

int main(){
	fastIO;
	cin >> n >> k;
	for(int i = 1;i<=n;i++)
	cin >> w[i];
	ll l = 0,r = (ll)1e10;
	ll m;
	while(r-l > 1){
		m = (l+r) / 2;
		if(maxm(m))
			l = m;
		else
			r = m;
	}
	ll y = k;
	for(int i = 1;i<=n;i++){
		if(w[i] < l){
			y -= l - w[i];
			w[i] = l;
		}
	}
	for(int i = 1;i<=n;i++){
		if(w[i] == l and y > 0){
			w[i] ++ ;
			y--;
		}
	}
	l = 0,r = (ll)1e10;
	while(r-l > 1){
		m = (l+r) / 2;
		if(minm(m))
			r = m;
		else
			l = m;
	}
	y = k;
	for(int i = 1;i<=n;i++){
		y -= max(0LL,w[i] - r);
		w[i] = min(w[i],r);
	}
	for(int i = 1;i<=n;i++)
		if(y > 0 and w[i] == r){
			w[i] -- ;
			y--;
		}
	sort(w+1,w+1+n);
	cout << w[n] - w[1] << "\n";
	return 0;
}