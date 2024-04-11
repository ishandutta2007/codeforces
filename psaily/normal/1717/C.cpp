#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353;
const ll inf=1ll<<60;
// head
const double eps=1e-12;
const int N=2e5+5; 



void solve() {
	int n;
	cin>>n;

	vector<int> a(n),b(n);
	vector<pair<int,int>> c(n);
	rep(i,0,n) cin>>a[i];
	rep(i,0,n) cin>>b[i];

	bool ok=true;

	rep(i,0,n) if (a[i]>b[i]) ok=false;

	/*
	rep(i,0,n) cout << a[i] << ' ' ;
	cout << endl;
	rep(i,0,n) cout << b[i] << ' ' ;
	cout << endl;
	*/

	int p=min_element(all(b))-b.begin();
	rep(i,0,n) a[i]=max(a[i],b[p]);

	rep(i,1,n) {
		int cur=(p-i+n)%n;

		if (a[cur]>b[cur]) ok=false;
		else if (a[cur]==b[cur]) ;
		else {
			if (b[cur]<=b[(cur+1)%n]+1) ;
			else ok=false;
		}
	}


	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;

}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int tt;
	cin>>tt;
	while (tt--) {
		solve();
	}

	return 0;
}