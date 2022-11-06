#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int MAX_N = int(1e5);
int n;
char a[MAX_N+10];
char b[MAX_N+10];

int main()
{
	cppio();

	int t; cin >> t;
for(;t--;) {
	cin >> n >> a >> b;

	auto f = [](char *s) -> vector<int> {
		vector<int> ret;

		char last = '0';
		for(int i=n-1; 0<=i; --i) {
			if (last != s[i]) {
				last = s[i];
				ret.pb(i+1);
			}
		}

		return ret;
	};

	auto va = f(a);
	auto vb = f(b);

	cout << (va.size() + vb.size()) << ' ';
	for(auto it = va.rbegin(); it != va.rend(); ++it)
		cout << (*it) << ' ';
	for(int x : vb) cout << x << ' ';
	cout << endl;
}
	return 0;
}