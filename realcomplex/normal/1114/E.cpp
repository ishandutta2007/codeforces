#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int ask1(int x){
	cout << "? " << x << endl;
	fflush(stdout);
	int y;
	cin >> y;
	return y;
}

int queries_asked = 0;

bool ask2(int x){
	queries_asked ++ ;
	cout << "> " << x << endl;
	fflush(stdout);
	int y;
	cin >> y;
	return y;
}

const int N = (int)1e6 + 9;
bool has[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	int l = 0,r = (int)1e9;
	int md;
	while(l < r){
		md = (l + r)/2;
		if(ask2(md))
			l = md + 1;
		else
			r = md;
	}
	vector<int> t;
	t.push_back(r);
	int maks = 60 - queries_asked;
	int u;
	for(int i = 0 ; i < min(maks, n); i ++  ){
		u = rnd() % n + 1;
		while(has[u]){
			u = rnd() % n + 1;
		}
		has[u] = true;
		t.push_back(ask1(u));
	}
	sort(t.begin(), t.end());
	int y = t[1] - t[0];
	for(int j = 2; j < t.size(); j ++ ){
		y = __gcd(y, t[j] - t[j - 1]);
	}
	cout << "! " << r - (n-1) * y << " " << y<<"\n";
	return 0;
}