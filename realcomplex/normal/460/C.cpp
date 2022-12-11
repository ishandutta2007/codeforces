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

const int N = (int)2e5 + 9;
ll a[N];
ll cnt[N];
int n,m,w;

void init(){
	for(int i = 0;i<N;i++)
		cnt[i] = 0;
}

bool can(ll u){
	init();
	ll curv;
	ll ad = 0;
	ll total = 0;
	for(int i = 1;i<=n;i++){
		ad -= cnt[i];
		curv = a[i] + ad;
		if(curv >= u)
			continue;
		curv = u-curv;
		total += curv;
		ad += curv;
		cnt[i+w] = curv;
	}
	if(total <= m)
		return true;
	else
		return false;
}

int main(){
	fastIO;
	cin >> n >> m >> w;
	for(int i = 1;i<=n;i++)
		cin >> a[i];
	ll l = 0,r = (ll)1e10;
	ll m;
	while(r-l>1){
		m = (l+r)/2;
		if(can(m))
			l = m;
		else
			r = m;
	}
	cout << l << " ";
	return 0;
}