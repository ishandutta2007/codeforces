#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

int n, m, t, a, b, c, d;
int arr[300005];
int val[600005][40];

random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<int> x(1, 1000);

int ft[300005][40];

void update(ll x, int idx, ll v) {
	for (; x < 300005; x += x & -x) ft[x][idx] += v;
}

int query(int x, int idx, int mod) {
	int sum = 0;
	for (; x; x -= x & -x) sum = sum + ft[x][idx];
	return sum % mod;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(unsigned(time(0)));
		gen.seed(23);
		cin >> n >> m;
		vector<ll> v;
		for (int i=0; i<n; i++) {
			cin >> arr[i];
			v.pb(arr[i]);
		}
		vector<tuple<int, int, int, int> > q;
		for (int i=0; i<m; i++) {
			cin >> a;
			if (a == 2) {
				cin >> b >> c >> d;
				q.emplace_back(a,b,c,d);
			}
			else {
				cin >> b >> c;
				q.emplace_back(a,b,c,0);
				v.pb(c);
			}
		}
		sort(all(v));
		
		for (int i=0; i<n+m+2; i++) {
			for (int j=0; j<40; j++){
				val[i][j] = x(gen);
			}
		}
		
		for (int i=0; i<n; i++) {
			arr[i] = lower_bound(all(v), arr[i]) - v.begin();
			for (int j=0; j<40; j++){
				update(i+1, j, val[arr[i]][j]);
			}
		}
		
		for (auto it : q) {
			tie(a,b,c,d) = it;
			if (a == 1) {
				c = lower_bound(all(v), c) - v.begin();
				for (int j=0; j<40; j++) {
					update(b, j, val[c][j]-val[arr[b-1]][j]);
				}
				arr[b-1] = c;
			}
			
			else {
				if (d == 1){
					cout << "YES\n";
					continue;
				}
				bool gd = true;
				for (int j=0; j<40; j++){
					ll x = query(c, j, d) - query(b-1, j, d) + 2*d;
					x %= d;
					if (x != 0) gd = false;
				}
				if (gd) cout << "YES\n";
				else cout << "NO\n";
			}
		}
}