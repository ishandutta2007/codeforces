#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 105;
ll a[N];
ll x[N];
ll y[N];

ll p[N];

ll ab(ll u){
	return max(u, -u);
}

int n;
ll d;

bool check(ll yd){
	for(int i = 0;i < n; i ++ )
		p[i] = -(ll)1e9;
	p[0] = yd;
	ll dis;
	for(int tr = 0; tr < n; tr ++ ){
	for(int i = 0; i < n;i ++ ){
		for(int j = 0; j < n;j ++ ){
			if(i == j)
				continue;
			dis = ab(x[i] - x[j]) + ab(y[i] - y[j]);
			p[j] = max(p[j], p[i] - (dis * d) + a[j]);
		}
	}
	}
	return p[n - 1] >= 0;
}

int main(){
	fastIO;
	cin >> n >> d;
	for(int i = 1; i < n-1; i ++ ){
		cin >> a[i];
	}
	for(int i = 0;i < n;i ++ ){
		cin >> x[i] >> y[i];
	}
	ll l = 0, r = (ll)1e9;
	ll md;
	while(l < r){
		md = (l + r)/2;
		if(check(md) == false){
			l = md + 1;
		}
		else{
			r = md;
		}
	}
	cout << r << "\n";
	return 0;
}