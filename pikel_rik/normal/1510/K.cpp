#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()


typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, a[N];

void swap1() {
	for (int i = 1; i <= n; i++) {
		swap(a[i], a[i + n]);
	}
}

void swap2() {
	for (int i = 1; i <= 2 * n; i += 2) {
		swap(a[i], a[i + 1]);
	}
}

void solve() {
	cin >> n;
	int ct = -1;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	for (int i = 0; i < 2 * n; i++) {
		if (a[1] == 1) {
			ct = i;
			break;
		}
		if (i & 1) swap2();
		else swap1();
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (a[i] != i) {
			deb1(-1)
			return;
		}
	}
	if(n & 1) deb1(min(ct, 2 * n - ct))
	else deb1(min(ct, 4 - ct))
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}